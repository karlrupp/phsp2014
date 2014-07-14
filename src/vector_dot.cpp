//
// Tutorial for demonstrating a simple OpenCL vector dot kernel
//
// Author: Karl Rupp    rupp@iue.tuwien.ac.at
//

typedef float       ScalarType;


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

// Helper include files taken from ViennaCL for error checking and timing
#include "ocl-error.hpp"


const char *my_opencl_program = ""
"__kernel void vec_dot(__global float *x,"
"                      __global float *y,"
"                      __global float *result,"
"                      unsigned int N)"
"{"
"  float thread_result = 0;"
"  for (unsigned int i  = get_global_id(0);"
"                    i  < N;"
"                    i += get_global_size(0))"
"    thread_result += x[i] * y[i];"
""
"  // write to shared local memory: \n"
"  __local float shared_array[128];"
"  shared_array[get_local_id(0)] = thread_result;"
""
"  // parallel reduction in shared local memory: \n"
"  for (uint stride=get_local_size(0)/2; stride > 0; stride /= 2)"
"  {"
"    barrier(CLK_LOCAL_MEM_FENCE);"
"    if (get_local_id(0) < stride)"
"      shared_array[get_local_id(0)] += shared_array[get_local_id(0) + stride]; "
"  } "
""
"  // write results to result array: \n"
"  if (get_local_id(0) == 0) "
"    result[get_group_id(0)] = shared_array[0]; "
"}";


int main()
{
  cl_int err;

  //
  /////////////////////////// Part 1: Set up an OpenCL context with one device ///////////////////////////////////
  //

  //
  // Query platform:
  //
  cl_uint num_platforms;
  cl_platform_id platform_ids[42];   //no more than 42 platforms supported...
  err = clGetPlatformIDs(42, platform_ids, &num_platforms); OPENCL_ERR_CHECK(err);
  std::cout << "# Platforms found: " << num_platforms << std::endl;
  cl_platform_id my_platform = platform_ids[0];


  //
  // Query devices:
  //
  cl_device_id device_ids[42];
  cl_uint num_devices;
  err = clGetDeviceIDs(my_platform, CL_DEVICE_TYPE_ALL, 42, device_ids, &num_devices); OPENCL_ERR_CHECK(err);
  std::cout << "# Devices found: " << num_devices << std::endl;
  cl_device_id my_device_id = device_ids[0];


  //
  // Create context:
  //
  cl_context my_context = clCreateContext(0, 1, &my_device_id, NULL, NULL, &err); OPENCL_ERR_CHECK(err);


  //
  // create a command queue for the device:
  //
  cl_command_queue my_queue = clCreateCommandQueue(my_context, my_device_id, 0, &err); OPENCL_ERR_CHECK(err);



  //
  /////////////////////////// Part 2: Create a program and extract kernels ///////////////////////////////////
  //

  //
  // Build the program:
  //
  size_t source_len = std::string(my_opencl_program).length();
  cl_program prog = clCreateProgramWithSource(my_context, 1, &my_opencl_program, &source_len, &err);
  err = clBuildProgram(prog, 0, NULL, NULL, NULL, NULL);
  if (err != CL_SUCCESS)
  {
    char buffer[8192];
    cl_build_status status;
    clGetProgramBuildInfo(prog, my_device_id, CL_PROGRAM_BUILD_STATUS, sizeof(cl_build_status), &status, NULL);
    clGetProgramBuildInfo(prog, my_device_id, CL_PROGRAM_BUILD_LOG,    sizeof(char)*8192, &buffer, NULL);
    std::cout << "Build Scalar: Err = " << err << " Status = " << status << std::endl;
    std::cout << "Log: " << buffer << std::endl;
    std::cout << "Sources: " << my_opencl_program << std::endl;
  }
  OPENCL_ERR_CHECK(err);

  //
  // Extract the only kernel in the program:
  //
  cl_kernel my_kernel = clCreateKernel(prog, "vec_dot", &err); OPENCL_ERR_CHECK(err);



  //
  /////////////////////////// Part 3: Create memory buffers ///////////////////////////////////
  //

  //
  // Set up buffers on host:
  //
  cl_uint vector_size = 128*1024;
  std::vector<ScalarType> x(vector_size, 1.0);
  std::vector<ScalarType> y(vector_size, 2.0);
  std::vector<ScalarType> result(128);  // holds result of each workgroup

  std::cout << std::endl;
  std::cout << "Vectors before kernel launch:" << std::endl;
  std::cout << "x: " << x[0] << " " << x[1] << " " << x[2] << " ..." << std::endl;
  std::cout << "y: " << y[0] << " " << y[1] << " " << y[2] << " ..." << std::endl;

  //
  // Now set up OpenCL buffers:
  //
  cl_mem ocl_x      = clCreateBuffer(my_context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, vector_size * sizeof(ScalarType), &(x[0]), &err); OPENCL_ERR_CHECK(err);
  cl_mem ocl_y      = clCreateBuffer(my_context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, vector_size * sizeof(ScalarType), &(y[0]), &err); OPENCL_ERR_CHECK(err);
  cl_mem ocl_result = clCreateBuffer(my_context, CL_MEM_READ_WRITE,                                128 * sizeof(ScalarType), NULL, &err); OPENCL_ERR_CHECK(err);


  //
  /////////////////////////// Part 4: Run kernel ///////////////////////////////////
  //
  size_t  local_size = 128;
  size_t global_size = 128*128;

  //
  // Set kernel arguments:
  //
  err = clSetKernelArg(my_kernel, 0, sizeof(cl_mem),  (void*)&ocl_x); OPENCL_ERR_CHECK(err);
  err = clSetKernelArg(my_kernel, 1, sizeof(cl_mem),  (void*)&ocl_y); OPENCL_ERR_CHECK(err);
  err = clSetKernelArg(my_kernel, 2, sizeof(cl_mem),  (void*)&ocl_result); OPENCL_ERR_CHECK(err);
  err = clSetKernelArg(my_kernel, 3, sizeof(cl_uint), (void*)&vector_size); OPENCL_ERR_CHECK(err);

  //
  // Enqueue kernel in command queue:
  //
  err = clEnqueueNDRangeKernel(my_queue, my_kernel, 1, NULL, &global_size, &local_size, 0, NULL, NULL); OPENCL_ERR_CHECK(err);



  //
  /////////////////////////// Part 5: Get data from OpenCL buffer ///////////////////////////////////
  //

  err = clEnqueueReadBuffer(my_queue, ocl_result, CL_TRUE, 0, 128 * sizeof(ScalarType), &(result[0]), 0, NULL, NULL); OPENCL_ERR_CHECK(err);

  ScalarType final_result = 0;
  for (size_t i=0; i<result.size(); ++i)
    final_result += result[i];

  std::cout << std::endl;
  std::cout << "Result of dot(x,y): " << final_result << std::endl;

  //
  // cleanup
  //
  clReleaseMemObject(ocl_x);
  clReleaseMemObject(ocl_y);
  clReleaseMemObject(ocl_result);
  clReleaseProgram(prog);
  clReleaseCommandQueue(my_queue);
  clReleaseContext(my_context);

  std::cout << std::endl;
  std::cout << "#" << std::endl;
  std::cout << "# My second OpenCL application finished successfully!" << std::endl;
  std::cout << "#" << std::endl;
  return EXIT_SUCCESS;
}


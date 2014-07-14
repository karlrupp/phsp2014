#ifndef OPENCL_ERROR_HPP_
#define OPENCL_ERROR_HPP_


/** @file ocl-error.hpp
    @brief Simple error checker for OpenCL (taken from ViennaCL and modified accordingly)
*/


#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

#include <string>
#include <iostream>
#include <exception>

  namespace ocl
  {
    //Wrapper for OpenCL exceptions:
    class device_not_found : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_DEVICE_NOT_FOUND \n Could not find a suitable device. Please check whether an OpenCL implementation is properly installed and a suitable device available.";
      }
    };

    class device_not_available : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_DEVICE_NOT_AVAILABLE \n Could not use the compute device because it is not available.";
      }
    };

    class compiler_not_available : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_COMPILER_NOT_AVAILABLE \n Your OpenCL framework does not provide an OpenCL compiler.";
      }
    };

    class mem_object_allocation_failure : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_MEM_OBJECT_ALLOCATION_FAILURE \n Could not allocate memory on the device. Most likely the device simply ran out of memory.";
      }
    };

    class out_of_resources : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_OUT_OF_RESOURCES \n Tried to launch a compute kernel, but the device does not provide enough resources. Try changing the global and local work item sizes.";
      }
    };

    class out_of_host_memory : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_OUT_OF_HOST_MEMORY \n The host ran out of memory (usually CPU RAM). Please try again on smaller problems.";
      }
    };

    class profiling_info_not_available : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_PROFILING_INFO_NOT_AVAILABLE.";
      }
    };

    class mem_copy_overlap : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_MEM_COPY_OVERLAP.";
      }
    };

    class image_format_mismatch : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_IMAGE_FORMAT_MISMATCH.";
      }
    };

    class image_format_not_supported : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_IMAGE_FORMAT_NOT_SUPPORTED.";
      }
    };

    class build_program_failure : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_BUILD_PROGRAM_FAILURE \n The OpenCL compiler encountered an error during the compilation of OpenCL sources.";
      }
    };

    class map_failure : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_MAP_FAILURE.";
      }
    };

    class invalid_value : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_VALUE.";
      }
    };

    class invalid_device_type : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_DEVICE_TYPE.";
      }
    };

    class invalid_platform : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_PLATFORM.";
      }
    };

    class invalid_device : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_DEVICE.";
      }
    };

    class invalid_context : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_CONTEXT.";
      }
    };

    class invalid_queue_properties : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_QUEUE_PROPERTIES.";
      }
    };

    class invalid_command_queue : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_COMMAND_QUEUE.";
      }
    };

    class invalid_host_ptr : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_HOST_PTR.";
      }
    };

    class invalid_mem_object : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_MEM_OBJECT.";
      }
    };

    class invalid_image_format_descriptor : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_IMAGE_FORMAT_DESCRIPTOR.";
      }
    };

    class invalid_image_size : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_IMAGE_SIZE.";
      }
    };

    class invalid_sampler : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_SAMPLER.";
      }
    };

    class invalid_binary : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_BINARY.";
      }
    };

    class invalid_build_options : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_BUILD_OPTIONS.";
      }
    };

    class invalid_program : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_PROGRAM.";
      }
    };

    class invalid_program_executable : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_PROGRAM_EXECUTABLE.";
      }
    };

    class invalid_kernel_name : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_KERNEL_NAME \n The supplied kernel name is invalid. If you have written your own OpenCL kernel, please check that the correct kernel name is used in the initalization of the kernel object.";
      }
    };

    class invalid_kernel_definition : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_KERNEL_DEFINITION.";
      }
    };

    class invalid_kernel : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_KERNEL \n The supplied kernel argument is invalid.";
      }
    };

    class invalid_arg_index : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_ARG_INDEX.";
      }
    };

    class invalid_arg_value : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_ARG_VALUE.";
      }
    };

    class invalid_arg_size : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_ARG_SIZE.";
      }
    };

    class invalid_kernel_args : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_KERNEL_ARGS \n The supplied kernel arguments do not fit the kernel parameter list. If you have written your own OpenCL kernel, please check that the correct kernel arguments are set in the appropriate order.";
      }
    };

    class invalid_work_dimension : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_WORK_DIMENSION";
      }
    };

    class invalid_work_group_size : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_WORK_GROUP_SIZE \n The supplied work group size is invalid. If you have set this value manually, please reconsider your choice.";
      }
    };

    class invalid_work_item_size : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_WORK_ITEM_SIZE \n The work item size is invalid. If you have set this value manually, please reconsider your choice.";
      }
    };

    class invalid_global_offset : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_GLOBAL_OFFSET.";
      }
    };

    class invalid_event_wait_list : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_EVENT_WAIT_LIST.";
      }
    };

    class invalid_event : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_EVENT.";
      }
    };

    class invalid_operation : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_OPERATION.";
      }
    };

    class invalid_gl_object : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_GL_OBJECT.";
      }
    };

    class invalid_buffer_size : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_BUFFER_SIZE.";
      }
    };

    class invalid_mip_level : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_MIP_LEVEL.";
      }
    };

    class invalid_global_work_size : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_GLOBAL_WORK_SIZE.";
      }
    };

    class invalid_property : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: CL_INVALID_PROPERTY.";
      }
    };

    class unknown_error : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: Encountered an unknown OpenCL error. In some cases, this might be due to an invalid global work size, but it can also be due to several compilation errors.";
      }
    };


    class double_precision_not_provided_error : public std::exception
    {
      virtual const char* what() const throw()
      {
        return "OpenCL: FATAL ERROR: You requested to use double precision. However, double precision is not supported by your device.";
      }
    };


    /** @brief An error reporting class. Template argument is used to avoid problems with external linkage.
    *
    *  Do not use this class directly, use the macro CL_ERROR_CHECK instead.
    *  @tparam T   Useless. Helps to avoid troubles with external linkage of namespace functions.
    */
    template <typename T>
    struct error_checker
    {

      /** @brief Trows exceptions that reflect OpenCL error codes */
      static void raise_exception(cl_int err)
      {
        switch (err)
        {
          case CL_DEVICE_NOT_FOUND:               throw device_not_found();
          case CL_DEVICE_NOT_AVAILABLE:           throw device_not_available();
          case CL_COMPILER_NOT_AVAILABLE:         throw compiler_not_available();
          case CL_MEM_OBJECT_ALLOCATION_FAILURE:  throw mem_object_allocation_failure();
          case CL_OUT_OF_RESOURCES:               throw out_of_resources();
          case CL_OUT_OF_HOST_MEMORY:             throw out_of_host_memory();
          case CL_PROFILING_INFO_NOT_AVAILABLE:   throw profiling_info_not_available();
          case CL_MEM_COPY_OVERLAP:               throw mem_copy_overlap();
          case CL_IMAGE_FORMAT_MISMATCH:          throw image_format_mismatch();
          case CL_IMAGE_FORMAT_NOT_SUPPORTED:     throw image_format_not_supported();
          case CL_BUILD_PROGRAM_FAILURE:          throw build_program_failure();
          case CL_MAP_FAILURE:                    throw map_failure();

          case CL_INVALID_VALUE:                  throw invalid_value();
          case CL_INVALID_DEVICE_TYPE:            throw invalid_device_type();
          case CL_INVALID_PLATFORM:               throw invalid_platform();
          case CL_INVALID_DEVICE:                 throw invalid_device();
          case CL_INVALID_CONTEXT:                throw invalid_context();
          case CL_INVALID_QUEUE_PROPERTIES:       throw invalid_queue_properties();
          case CL_INVALID_COMMAND_QUEUE:          throw invalid_command_queue();
          case CL_INVALID_HOST_PTR:               throw invalid_host_ptr();
          case CL_INVALID_MEM_OBJECT:             throw invalid_mem_object();
          case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR: throw invalid_image_format_descriptor();
          case CL_INVALID_IMAGE_SIZE:             throw invalid_image_size();
          case CL_INVALID_SAMPLER:                throw invalid_sampler();
          case CL_INVALID_BINARY:                 throw invalid_binary();
          case CL_INVALID_BUILD_OPTIONS:          throw invalid_build_options();
          case CL_INVALID_PROGRAM:                throw invalid_program();
          case CL_INVALID_PROGRAM_EXECUTABLE:     throw invalid_program_executable();
          case CL_INVALID_KERNEL_NAME:            throw invalid_kernel_name();
          case CL_INVALID_KERNEL_DEFINITION:      throw invalid_kernel_definition();
          case CL_INVALID_KERNEL:                 throw invalid_kernel();
          case CL_INVALID_ARG_INDEX:              throw invalid_arg_index();
          case CL_INVALID_ARG_VALUE:              throw invalid_arg_value();
          case CL_INVALID_ARG_SIZE:               throw invalid_arg_size();
          case CL_INVALID_KERNEL_ARGS:            throw invalid_kernel_args();
          case CL_INVALID_WORK_DIMENSION:         throw invalid_work_dimension();
          case CL_INVALID_WORK_GROUP_SIZE:        throw invalid_work_group_size();
          case CL_INVALID_WORK_ITEM_SIZE:         throw invalid_work_item_size();
          case CL_INVALID_GLOBAL_OFFSET:          throw invalid_global_offset();
          case CL_INVALID_EVENT_WAIT_LIST:        throw invalid_event_wait_list();
          case CL_INVALID_EVENT:                  throw invalid_event();
          case CL_INVALID_OPERATION:              throw invalid_operation();
          case CL_INVALID_GL_OBJECT:              throw invalid_gl_object();
          case CL_INVALID_BUFFER_SIZE:            throw invalid_buffer_size();
          case CL_INVALID_MIP_LEVEL:              throw invalid_mip_level();
          case CL_INVALID_GLOBAL_WORK_SIZE:       throw invalid_global_work_size();
      #ifdef CL_INVALID_PROPERTY
    case CL_INVALID_PROPERTY:               throw invalid_property();
      #endif
          //  return "CL_INVALID_GLOBAL_WORK_SIZE";

          default: throw unknown_error();
        }

      } //getErrorString

      /** @brief Checks whether an OpenCL error has occured.
      *
      *  Do not use this function directly, use the macro CL_ERROR_CHECK instead.
      */
      static void checkError(cl_int err,
                             const std::string & file,
                             const std::string & func,
                             int line)
      {
        if (err != CL_SUCCESS)
        {
          std::cerr << "OpenCL: Error " << err  << " in function " << func << " ( "<< file << ":" << line << " ) " << std::endl;
          raise_exception(err);
        }
      } //checkError()

    }; //struct

  } //namespace ocl

#define OPENCL_ERR_CHECK(err) ocl::error_checker<void>::checkError(err, __FILE__, __FUNCTION__, __LINE__);


#endif


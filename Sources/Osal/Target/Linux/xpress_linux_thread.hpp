#pragma once 

#include <pthread.h>
#include <cstdint>
#include "xpress_linux_misc.hpp"


namespace xpress
{
  /**
   * @brief 
   */
  typedef enum 
  {
    os_priority_min = 0,
    os_priority_low  = 10,
    os_priority_mid  = 50,
    os_priority_high = 80,
    os_priority_max = 99,
  }os_priority;
}

namespace xpress::linux
{


  /**
   * @brief 
   *
   * @tparam __user_implimented_thread_class
   */
  template<class __user_implimented_thread_class>
  class thread final:public __user_implimented_thread_class
  {
    private:
      __user_implimented_thread_class m_user_thread;

      /**
       * @Synopsis  
       *
       * @Param ap_args
       *
       * @Returns   
       */
      static void *thread_main_function(void*ap_args)
      {
        /* cast to self obect */
        xpress::linux::thread<__user_implimented_thread_class> self
          = static_cast<xpress::linux::thread<__user_implimented_thread_class>>(ap_args);

        /* call user implimented class function "main" */
        self->m_user_thread.main();

        return nullptr;
      }

    protected:
      /* nothing */

    public:
      /**
       * @brief 
       */
      typedef enum 
      {
        success = 0x00,
      }error_enum_t;

      /**
       * @brief 
       */
      typedef enum 
      {
        wait = 0x00,
      }status_t;

      /**
       * @brief 
       */
      thread()
      {
      }


      /**
       * @brief 
       */
      virtual ~thread()
      {
      }

      /**
       * @brief 
       * set thread priority
       *
       * @param a_priority_param
       *
       * @return 
       */
      error_enum_t priority(const xpress::os_priority a_priority_param)
      {
        return success;
      }

      /**
       * @brief 
       *
       * @return 
       */
      xpress::os_priority priority(void)
      {
        return os_priority_min;
      }

      
      /**
       * @brief 
       *
       * @param a_stack_size
       *
       * @return 
       */
      error_enum_t stack_size(const uint64_t a_stack_size)
      {
        return success;
      }

      /**
       * @brief 
       *
       * @return 
       */
      error_enum_t create(void)
      {
        return success;
      }

      /**
       * @brief 
       *
       * @return 
       */
      error_enum_t run(void)
      {
        return success;
      }

      /**
       * @brief 
       *
       * @return 
       */
      error_enum_t join(void)
      {
        return success;
      }

      /**
       * @brief 
       *
       * @return 
       */
      error_enum_t stop(void)
      {
        return success;
      }

      /**
       * @brief 
       *
       * @return 
       */
      error_enum_t destroy(void)
      {
        return success;
      }

      /**
       * @brief 
       *
       * @return 
       */
      status_t status(void)
      {
        return wait;
      }

  };
}

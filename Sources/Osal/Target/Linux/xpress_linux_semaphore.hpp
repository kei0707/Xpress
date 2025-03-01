#pragma once

#include "xpress_linux_oserror.hpp"
#include <cstdint>
#include <semaphore.h>
#include <string>

namespace xpress::linux
{
  class semaphore final : public xpress::linux::oserror
  {
    private:
      sem_t* mp_sem_t;

    protected:
      /* nothing */
    public:
      /**
       * @brief 
       */
      semaphore();

      /**
       * @brief 
       */
      virtual ~semaphore();

      /**
       * @brief 
       *
       * @return 
       */
      int32_t create(
          const std::string a_name,
          const uint32_t a_init_count = 0);

      /**
       * @brief 
       *
       * @return 
       */
      int32_t take(void);

      /**
       * @brief 
       *
       * @param a_timeout_us
       *
       * @return 
       */
      int32_t take(const uint64_t a_timeout_us);

      /**
       * @brief 
       *
       * @return 
       */
      int32_t give(void);

      /**
       * @brief 
       *
       * @return 
       */
      virtual std::string get_error_msg(void) override;

  };
}

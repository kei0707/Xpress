#include "xpress_linux_semaphore.hpp"
#include "xpress_linux_misc.hpp"
#include <fcntl.h>
#include <sys/stat.h>


/**
 * @brief 
 */
xpress::linux::semaphore::semaphore()
  : xpress::linux::oserror(), mp_sem_t(nullptr)
{
}

/**
 * @brief 
 */
xpress::linux::semaphore::~semaphore()
{
}

/**
 * @brief 
 *
 * @return 
 */
int32_t xpress::linux::semaphore::create(
    const std::string a_name,
    const uint32_t a_init_count)
{
  /* open named semaphore */
  mp_sem_t = sem_open(a_name.c_str(),O_CREAT|O_EXCL,0x777,a_init_count);
  if(SEM_FAILED == mp_sem_t)
  {
    return get_errorno();
  }
  return 0;
}

/**
 * @brief 
 *
 * @return 
 */
int32_t xpress::linux::semaphore::take(void)
{
  return get_errorno();
}

/**
 * @brief 
 *
 * @param a_timeout_us
 *
 * @return 
 */
int32_t xpress::linux::semaphore::take(const uint64_t a_timeout_us)
{
  return get_errorno();
}

/**
 * @brief 
 *
 * @return 
 */
int32_t xpress::linux::semaphore::give(void)
{
  return get_errorno();
}

/**
 * @brief 
 *
 * @return 
 */
std::string xpress::linux::semaphore::get_error_msg(void)
{
  std::string msg = "success";
  return msg;
}


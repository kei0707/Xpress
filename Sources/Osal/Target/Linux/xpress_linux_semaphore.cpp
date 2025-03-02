#include "xpress_linux_semaphore.hpp"
#include "xpress_linux_timer.hpp"
#include "xpress_linux_misc.hpp"
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>



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
  /* chack name-length */
  if((NAME_MAX-4) < a_name.length())
  {
    return -1;
  }

  /* open named semaphore */
  mp_sem_t = sem_open(a_name.c_str(),O_CREAT|O_EXCL,0x777,a_init_count);
  if(SEM_FAILED == mp_sem_t)
  {
    return get_errorno();
  }

  return ERROR_NONE;
}


/**
 * @brief 
 *
 * @return 
 */
int32_t xpress::linux::semaphore::destroy(void)
{
  int32_t ret = sem_destroy(mp_sem_t);
  if(-1 == ret)
  {
    return get_errorno();
  }

  return ERROR_NONE;
}

/**
 * @brief 
 *
 * @return 
 */
int32_t xpress::linux::semaphore::take(void)
{
  int32_t ret = sem_wait(mp_sem_t);
  if(-1 == ret)
  {
    return get_errorno();
  }

  return ERROR_NONE;
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
  uint64_t sec,nsec;
  struct timespec ts;
  struct timespec cur;

  /* convert timeout-usec  to (sec,nsec)*/ 
  local::timer::convert(a_timeout_us,sec,nsec);

  /* set timespec parameter */
  local::timer::set_timespec(sec,nsec,ts);

  /* get current system time */
  local::timer::now(cur);

  /* add current timespec */
  ts.tv_sec += cur.tv_sec;
  ts.tv_nsec+= cur.tv_nsec;

  /* semaphore take untile timeout */
  int32_t ret = sem_timedwait(mp_sem_t,&ts);
  if(-1 == ret)
  {
    return get_errorno();
  }

  return ERROR_NONE;
}

/**
 * @brief 
 *
 * @return 
 */
int32_t xpress::linux::semaphore::give(void)
{
  int32_t ret = sem_post(mp_sem_t);
  if(-1 == ret)
  {
    return get_errorno();
  }

  return ERROR_NONE;
}

/**
 * @brief 
 *
 * @return 
 */
std::string xpress::linux::semaphore::get_error_msg(void)
{
  std::string msg = "";

  switch(m_errorno)
  {
    case ERROR_NONE:
      msg = "NO ERROR";
      break;
    case EINVAL:
      break;
    default:
      msg = "UNKNOWN ERROR CODE " + std::to_string(m_errorno);
      break;
  }

  return msg;
}


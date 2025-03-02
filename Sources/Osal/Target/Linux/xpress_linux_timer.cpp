#include "xpress_linux_timer.hpp"


void xpress::linux::local::timer::convert(
      const uint64_t a_usec,
      uint64_t& a_sec,
      uint64_t& a_nsec)
{
  a_sec  = a_usec / 1e6 ;
  a_nsec = a_usec - ( a_sec * 1e6);
  return;
}


/**
 * @brief 
 *
 * @param a_sec
 * @param a_nsec
 * @param a_result
 */
void xpress::linux::local::timer::set_timespec(
      const uint64_t a_sec,
      const uint64_t a_nsec,
      struct timespec& a_result)
{
  a_result.tv_sec = a_sec;
  a_result.tv_nsec = a_nsec;

  return;
}

/**
 * @brief 
 *
 * @param a_resut
 *
 * @return 
 */
int32_t xpress::linux::local::timer::now(struct timespec& a_result)
{
  return clock_gettime(CLOCK_MONOTONIC,&a_result);
}

/**
 * @brief
 */
xpress::linux::timer::timer() {}

/**
 * @brief
 */
xpress::linux::timer::~timer() {}

/**
 * @brief 
 *
 * @param a_nsec
 */
void xpress::linux::timer::nsec(uint64_t a_nsec) { return; }

/**
 * @brief 
 *
 * @param a_usec
 */
void xpress::linux::timer::usec(uint64_t a_usec) { return; }

/**
 * @brief 
 *
 * @param a_msec
 */
void xpress::linux::timer::msec(uint64_t a_msec) { return; }

/**
 * @brief 
 *
 * @param a_sec
 */
void xpress::linux::timer::sec(uint64_t a_sec) { return; }

/**
 * @brief 
 *
 * @return 
 */
bool xpress::linux::timer::create(void) { return false; }

/**
 * @brief 
 *
 * @return 
 */
bool xpress::linux::timer::reset(void) { return false; }

/**
 * @brief 
 *
 * @return 
 */
bool xpress::linux::timer::start(void) { return false; }

/**
 * @brief 
 *
 * @return 
 */
bool xpress::linux::timer::stop(void) { return false; }

/**
 * @brief 
 *
 * @return 
 */
bool xpress::linux::timer::is_expired(void) { return false; }

/**
 * @brief 
 *
 * @return 
 */
std::string xpress::linux::timer::get_error_msg(void)
{
  std::string ret = "";
  return ret;
}

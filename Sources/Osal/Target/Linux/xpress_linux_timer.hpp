#pragma once

#include "xpress_linux_misc.hpp"
#include "xpress_linux_oserror.hpp"

#include <cstdint>
#include <sys/timerfd.h>

namespace xpress::linux::local::timer {
void convert(const uint64_t a_usec, uint64_t &a_sec, uint64_t &a_nsec);

void set_timespec(const uint64_t a_sec, const uint64_t a_nsec,
                  struct timespec &a_result);

int32_t now(struct timespec &a_result);
} // namespace xpress::linux::local::timer

namespace xpress::linux {
class timer final : public xpress::linux::oserror {
private:
  int32_t m_tfd;
  uint64_t m_time;

protected:
public:
  timer();
  virtual ~timer();

  void nsec(uint64_t a_nsec);
  void usec(uint64_t a_usec);
  void msec(uint64_t a_msec);
  void sec(uint64_t a_sec);

  bool create(void);

  bool reset(void);
  bool start(void);
  bool stop(void);
  bool is_expired(void);

  virtual std::string get_error_msg(void) override;
};
} // namespace xpress::linux

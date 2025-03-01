#pragma once

#include <string>
#include <mutex>
#include <cstdint>
#include <cstdio>


namespace xpress::linux::misc::local
{
  static std::mutex gs_io_mutex_t;
}

namespace xpress::linux
{

  /**
   * @brief 
   *
   * @tparam Args
   * @param ap_fmt
   * @param ...args
   */
  template<typename ... Args>
  void printf(const char *ap_fmt,
      Args const & ...args)
    {
      std::unique_lock<std::mutex> lock(xpress::linux::misc::local::gs_io_mutex_t);
      ::printf(ap_fmt,args ...);
      return;
    }
}

#pragma once

#if defined(XPRESS_OSAL_TARGET_LINUX)
#include "Target/Linux/xpress_linux.hpp"
namespace xpress {
namespace osal = linux;
}
#elif defined(XPRESS_OSAL_TARGET_FREERTOS)
#include "Target/FreeRTOS/xpress_freertos.hpp"
namespace xpress {
namespace osal = freertos;
}
#else
#error "$$$$ xpress $$$$ osal target not defined."
#endif

#include "Adapter/xpress_osal_thread.hpp"

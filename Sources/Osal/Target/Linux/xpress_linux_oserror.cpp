#include <error.h>
#include "xpress_linux_oserror.hpp"

/**
 * @brief 
 */
xpress::linux::oserror::oserror()
  :m_errorno(0)
{
}

/**
 * @brief 
 */
xpress::linux::oserror::~oserror()
{
}

/**
 * @brief 
 *
 * @return 
 */
int xpress::linux::oserror::get_errorno(void)
{
  m_errorno = errno;
  return m_errorno;
}

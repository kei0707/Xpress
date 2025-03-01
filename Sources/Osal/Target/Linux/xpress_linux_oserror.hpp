#pragma once

#include <string>


namespace xpress::linux
{
  class oserror 
  {
    private:
      int m_errorno;
    protected:
      /**
       * @brief 
       */
      oserror();

      /**
       * @brief 
       */
      ~oserror();

      int get_errorno(void);

    public:
      virtual std::string get_error_msg(void) = 0;
  };
}

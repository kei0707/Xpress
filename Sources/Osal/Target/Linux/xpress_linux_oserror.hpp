#pragma once

#include <string>


namespace xpress::linux
{
  class oserror 
  {
    private:
    protected:
      int m_errorno;
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

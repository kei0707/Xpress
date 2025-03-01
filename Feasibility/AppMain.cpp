#include <cstdio>
#include "xpress.hpp"

int main(void)
{
  printf("Hi\n");
  xpress::linux::printf("Hi %s \n",__PRETTY_FUNCTION__);
  return 0;
}

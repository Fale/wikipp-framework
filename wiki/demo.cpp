#include <iostream>
#include <string>

#define HTTP_WGET

#include <wiki/categories.h>

int main()
{
  wikipp::wiki::categories categories;
  std::cout << categories.countMembers( "en.wikipedia.org", "Qt" ) << std::endl;
  return 0;
}
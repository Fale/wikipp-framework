/*
Copyright (C) 2009 Fabio Alessandro Locati - fabiolocati@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <string>

#include <libs/convert.h>

bool toInt()
{
  int var;
  var = toInt( "123" );
  std::cout << "CONVERT.toInt: OK" << std::endl;
  return 0;
}

bool toChar()
{
  const char *var;
  var = toChar( "hello world" );
  std::cout << "CONVERT.toChar: OK" << std::endl;
  return 0;
}

bool toString()
{
  std::string var( "hello world" );
  std::cout << "CONVERT.toString: OK" << std::endl;
  return 0;
}

int main()
{
  int results;

  results = toInt();
  results = results + toChar();
  results = results + toString();

  if ( results == 0 )
    std::cout << "Perfect" << std::endl;
  else
    std::cout << "Errors detected" << std::endl;
  return 0;
}
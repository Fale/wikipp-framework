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

#include <http/asio.h>

bool get()
{
  if ( wikipp::http::asio::get( "wikipp.net", "testGet.php" ) == "testOk" )
  {
    std::cout << "ASIO.Get: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "ASIO.Get: Error" << std::endl;
    return 1;
  }
}

bool post()
{
  if ( wikipp::http::asio::post( "wikipp.net", "testPost.php", "test=test" ) == "testOk" )
  {
    std::cout << "ASIO.Post: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "ASIO.Post: Error" << std::endl;
    return 1;
  }
}

int main()
{
  int results;

  results = get();
  results = results + post();

  if ( results == 0 )
    std::cout << "Perfect" << std::endl;
  else
    std::cout << "Errors detected" << std::endl;
  return 0;
}
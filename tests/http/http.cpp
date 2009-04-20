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

#include <http/http.h>

bool backends()
{
  wikipp::http::http http;
  http.setBackend( "wget" );
  if ( http.getBackend() == "wget" )
  {
    std::cout << "HTTP.Backends: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.Backends: Error" << std::endl;
    return 1;
  }
}

bool useragent()
{
  wikipp::http::http http;
  http.setUserAgent( "mozilla" );
  if ( http.getUserAgent() == "mozilla" )
  {
    std::cout << "HTTP.UserAgent: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.UserAgent: Error" << std::endl;
    return 1;
  }
}

bool igetasio()
{
  wikipp::http::http http;
  http.setBackend( "asio" );
  if ( http.iget( "wikipp.net", "testGet.php" ) == "testOk" )
  {
    std::cout << "HTTP.Asio.IGet: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.Asio.IGet: Error" << std::endl;
    return 1;
  }
}

bool ipostasio()
{
  wikipp::http::http http;
  http.setBackend( "asio" );
  if ( http.ipost( "wikipp.net", "testPost.php", "test=test" ) == "testOk" )
  {
    std::cout << "HTTP.Asio.IPost: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.Asio.IPost: Error" << std::endl;
    return 1;
  }
}

bool igetwget()
{
  wikipp::http::http http;
  http.setBackend( "wget" );
  if ( http.iget( "wikipp.net", "testGet.php" ) == "testOk" )
  {
    std::cout << "HTTP.Wget.IGet: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.Wget.IGet: Error" << std::endl;
    return 1;
  }
}

bool ipostwget()
{
  wikipp::http::http http;
  http.setBackend( "wget" );
  if ( http.ipost( "wikipp.net", "testPost.php", "test=test" ) == "testOk" )
  {
    std::cout << "HTTP.Wget.IPost: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.Wget.IPost: Error" << std::endl;
    return 1;
  }
}

bool getasio()
{
  if ( wikipp::http::http::get( "wikipp.net", "testGet.php", "asio" ) == "testOk" )
  {
    std::cout << "HTTP.Asio.Get: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.Asio.Get: Error" << std::endl;
    return 1;
  }
}

bool postasio()
{
  if ( wikipp::http::http::post( "wikipp.net", "testPost.php", "test=test", "asio" ) == "testOk" )
  {
    std::cout << "HTTP.Asio.Post: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.Asio.Post: Error" << std::endl;
    return 1;
  }
}

bool getwget()
{
  if ( wikipp::http::http::get( "wikipp.net", "testGet.php", "wget" ) == "testOk" )
  {
    std::cout << "HTTP.Wget.Get: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.Wget.Get: Error" << std::endl;
    return 1;
  }
}

bool postwget()
{
  if ( wikipp::http::http::post( "wikipp.net", "testPost.php", "test=test", "wget" ) == "testOk" )
  {
    std::cout << "HTTP.Wget.Post: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "HTTP.Wget.Post: Error" << std::endl;
    return 1;
  }
}

int main()
{
  int results;

  results = backends();
  results = results + useragent();
  results = results + igetwget();
  results = results + ipostwget();
  results = results + igetasio();
  results = results + ipostasio();
  results = results + getwget();
  results = results + postwget();
  results = results + getasio();
  results = results + postasio();

  if ( results == 0 )
    std::cout << "Perfect" << std::endl;
  else
    std::cout << "Errors detected" << std::endl;
  return 0;
}
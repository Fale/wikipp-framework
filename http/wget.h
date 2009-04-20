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

#ifndef WIKIPP_HTTP_WGET_H
#define WIKIPP_HTTP_WGET_H

#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace wikipp
{
  namespace http
  {
    /**
    * Class that takes care about sending and receiving HTTP data throughtout WGET
    *
    * @author Fabio Alessandro Locati
    */
    class wget
    {
      public:
        static std::string getRaw( std::string, std::string, bool cookies = 1, std::string ua = "Wiki++ Framework v0.2" );
        /**
        * Function that allows you to create and send an HTTP/GET request
        *
        * This function returns the response of an HTTP/GET request without headers.
        *
        * @code
        * std::cout << wikipp::http::wget::get( "en.wikipedia.org", "wiki/Main_Page" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param ua The User Agent that will be sent in the request.
        * @return The HTML of the page.
        */
        static std::string get( std::string, std::string, bool cookies = 1, std::string ua = "Wiki++ Framework v0.2" );

        static std::string postRaw( std::string, std::string, std::string, bool cookies = 1, std::string ua = "Wiki++ Framework v0.2" );
        /**
        * Function that allows you to create and send an HTTP/POST request
        *
        * This function returns the response of an HTTP/POST request without headers.
        *
        * @code
        * std::cout << wikipp::http::wget::post( "en.wikipedia.org", "wiki/Main_Page", "user=name&pass=password" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param postData The list of the post values, in the form: var=value&var=value&var=value.
        * @param ua The User Agent that will be sent in the request.
        * @return The HTML of the page.
        */
        static std::string post( std::string, std::string, std::string, bool cookies = 1, std::string ua = "Wiki++ Framework v0.2" );

        /**
        * Function that is the backend of wikipp::http::wget::get and wikipp::http::wget::post.
        * @deprecated This function should NOT be used directly.
        */
        static std::string procedure( std::string );
    };
  }
}
#endif

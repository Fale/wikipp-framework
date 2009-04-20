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

#ifndef WIKIPP_HTTP_ASIO_H
#define WIKIPP_HTTP_ASIO_H

#include <iostream>
#include <string>
#include <fstream>

#include <boost/asio.hpp>
#include <boost/regex.hpp>

using boost::asio::ip::tcp;

namespace wikipp
{
  namespace http
  {
    /**
    * Class that takes care about sending and receiving HTTP data throughtout ASIO
    *
    * @author Fabio Alessandro Locati
    */
    class asio
    {
      public:

        /**
        * Function that allows you to create and send an HTTP/GET request
        *
        * This function returns the response of an HTTP/GET request in a "raw" way.
        * For "raw" is meaning that the headers are included.
        *
        * @code
        * std::cout << wikipp::http::asio::getRaw( "en.wikipedia.org", "wiki/Main_Page", 0 ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param loadCookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The User Agent that will be sent in the request.
        * @return The HTML of the page with the headers on top.
        *
        * @see get
        */
        static std::string getRaw( const std::string&, const std::string&, bool loadCookies = 1, std::string const& ua = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/GET request
        *
        * This function returns the response of an HTTP/GET request without headers.
        *
        * @code
        * std::cout << wikipp::http::asio::get( "en.wikipedia.org", "wiki/Main_Page", 0 ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param loadCookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The User Agent that will be sent in the request.
        * @return The HTML of the page.
        *
        * @see getRaw
        */
        static std::string get( const std::string&, const std::string&, bool loadCookies = 1, std::string const& ua = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/POST request
        *
        * This function returns the response of an HTTP/POST request in a "raw" way.
        * For "raw" is meaning that the headers are included.
        *
        * @code
        * std::cout << wikipp::asio::http::postRaw( "en.wikipedia.org", "wiki/Main_Page", "user=name&pass=password", 0 ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param postData The list of the post values, in the form: var=value&var=value&var=value.
        * @param loadCookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The User Agent that will be sent in the request.
        * @return The HTML of the page with the headers on top.
        *
        * @see post
        */
        static std::string postRaw( const std::string&, const std::string&, std::string, bool loadCookies = 1, std::string const& ua = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/POST request
        *
        * This function returns the response of an HTTP/POST request without headers.
        *
        * @code
        * std::cout << wikipp::http::asio::post( "en.wikipedia.org", "wiki/Main_Page", "user=name&pass=password", 0 ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param postData The list of the post values, in the form: var=value&var=value&var=value.
        * @param loadCookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The User Agent that will be sent in the request.
        * @return The HTML of the page.
        *
        * @see postRaw
        */
        static std::string post( const std::string&, const std::string&, std::string, bool loadCookies = 1, std::string const& ua = "Wiki++ Framework v0.2" );
    };
  }
}
#endif

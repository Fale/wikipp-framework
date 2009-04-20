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

#ifndef WIKIPP_HTTP_H
#define WIKIPP_HTTP_H

#include <string>

#include "asio.h"
#include "wget.h"

namespace wikipp
{
  namespace http
  {
    /**
    * Class that takes care about sending and receiving HTTP data throughtout different backends.
    *
    * The class wikipp::http::http allows you to acceed to every single backend using an unique API.
    * This class should be preferred to every other in the wikipp::http namespace. Using this class
    * instead of a different one from this namespace is meaning allow the person that will execute
    * your bot to choose the backend in the case that the default backend is not available on his
    * system or does not respond correctly to his needs.
    *
    * @author Fabio Alessandro Locati
    */
    class http
    {
      public:
        /**
        * The function is the costructor of this class.
        *
        * Even if constract an istance of this class will allow you to have more options,
        * you can even use the wikipp::http::http::get() and wikipp::http::http::post()
        * function without do this.
        *
        * @code
        * wikipp::http::http http;
        * @endcode
        *
        * @param bkd The backend you want to set as default for your HTTP calls (default: "wget")
        * @param ua The UserAgent you want to set as default for your HTTP calls (default: "Wiki++ Framework v0.2")
        */
        http( std::string bkd = "wget", std::string ua = "Wiki++ Framework v0.2" );

        /**
        * Function to set the UserAgent that will appear on your HTTP calls.
        *
        * You can not set this, because it have been already set in the class instantiation.
        *
        * @param ua The UserAgent you want to set as default for your HTTP calls.
        *
        * @see http
        * @see getUserAgent
        */
        void setUserAgent( std::string );

        /**
        * Function to set the Backend that will be used for your HTTP calls.
        *
        * You can not set this, because it have been already set in the class instantiation.
        *
        * @param bkd The backend you want to set as default for your HTTP calls
        *
        * @see http
        * @see getBackend
        */
        void setBackend( std::string );

        /**
        * Function to get the UserAgent.
        *
        * @return The UserAgent you have setted before
        *
        * @see http
        * @see setUserAgent
        */
        std::string getUserAgent();

        /**
        * Function to get the Backend.
        *
        * @return The Backend you have setted before
        *
        * @see http
        * @see setBackend
        */
        std::string getBackend();

        /**
        * Function that allows you to create and send an HTTP/GET request
        *
        * This function returns the response of an HTTP/GET request with headers.
        * This function, in reality, is a sort of virtual function, a fronend for the
        * get function of every backend.
        *
        * @code
        * wikipp::http::http http;
        * std::cout << http.igetRaw( "en.wikipedia.org", "wiki/Main_Page" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param cookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The UserAgent you want to set for this HTTP call (default: "Wiki++ Framework v0.2")
        * @return The HTML of the page.
        */
        std::string igetRaw( std::string, std::string, bool cookies = 1, std::string ua  = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/GET request
        *
        * This function returns the response of an HTTP/GET request without headers.
        * This function, in reality, is a sort of virtual function, a fronend for the
        * get function of every backend.
        *
        * @code
        * wikipp::http::http http;
        * std::cout << http.iget( "en.wikipedia.org", "wiki/Main_Page" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param cookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The UserAgent you want to set for this HTTP call (default: "Wiki++ Framework v0.2")
        * @return The HTML of the page.
        */
        std::string iget( std::string, std::string, bool cookies = 1, std::string ua  = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/POST request
        *
        * This function returns the response of an HTTP/POST request with headers.
        * This function, in reality, is a sort of virtual function, a fronend for the
        * get function of every backend.
        *
        * @code
        * wikipp::http::http http;
        * std::cout << http.ipostRaw( "en.wikipedia.org", "wiki/Main_Page", "user=name&pass=password" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param postValues The list of the post values, in the form: var=value&var=value&var=value.
        * @param cookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The UserAgent you want to set for this HTTP call (default: "Wiki++ Framework v0.2")
        * @return The HTML of the page.
        */
        std::string ipostRaw( std::string, std::string, std::string, bool cookies = 1, std::string ua  = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/POST request
        *
        * This function returns the response of an HTTP/POST request without headers.
        * This function, in reality, is a sort of virtual function, a fronend for the
        * get function of every backend.
        *
        * @code
        * wikipp::http::http http;
        * std::cout << http.ipost( "en.wikipedia.org", "wiki/Main_Page", "user=name&pass=password" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param postValues The list of the post values, in the form: var=value&var=value&var=value.
        * @param cookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The UserAgent you want to set for this HTTP call (default: "Wiki++ Framework v0.2")
        * @return The HTML of the page.
        */
        std::string ipost( std::string, std::string, std::string, bool cookies = 1, std::string ua  = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/GET request
        *
        * This function returns the response of an HTTP/GET request with headers.
        * This function, in reality, is a sort of virtual function, a fronend for the
        * get function of every backend.
        *
        * @code
        * std::cout << wikipp::http::http::getRaw( "en.wikipedia.org", "wiki/Main_Page" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param cookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The UserAgent you want to set for this HTTP call (default: "Wiki++ Framework v0.2")
        * @return The HTML of the page.
        */
        static std::string getRaw( std::string, std::string, bool cookies = 1, std::string bkd = "wget", std::string ua  = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/GET request
        *
        * This function returns the response of an HTTP/GET request without headers.
        * This function, in reality, is a sort of virtual function, a fronend for the
        * get function of every backend.
        *
        * @code
        * std::cout << wikipp::http::http::get( "en.wikipedia.org", "wiki/Main_Page" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param cookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The UserAgent you want to set for this HTTP call (default: "Wiki++ Framework v0.2")
        * @return The HTML of the page.
        */
        static std::string get( std::string, std::string, bool cookies = 1, std::string bkd = "wget", std::string ua  = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/POST request
        *
        * This function returns the response of an HTTP/POST request with headers.
        * This function, in reality, is a sort of virtual function, a fronend for the
        * get function of every backend.
        *
        * @code
        * std::cout << wikipp::http::http::postRaw( "en.wikipedia.org", "wiki/Main_Page", "user=name&pass=password" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param postValues The list of the post values, in the form: var=value&var=value&var=value.
        * @param cookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The UserAgent you want to set for this HTTP call (default: "Wiki++ Framework v0.2")
        * @return The HTML of the page.
        */
        static std::string postRaw( std::string, std::string, std::string, bool cookies = 1, std::string bkd = "wget", std::string ua  = "Wiki++ Framework v0.2" );

        /**
        * Function that allows you to create and send an HTTP/POST request
        *
        * This function returns the response of an HTTP/POST request without headers.
        * This function, in reality, is a sort of virtual function, a fronend for the
        * get function of every backend.
        *
        * @code
        * std::cout << wikipp::http::http::post( "en.wikipedia.org", "wiki/Main_Page", "user=name&pass=password" ) << std::endl;
        * @endcode
        *
        * @param url The url of the web site (ie: en.wikipedia.org) (Do not put "http://" in front).
        * @param link The path of the file you want (ie: index.html) (Do not put "/" in front).
        * @param postValues The list of the post values, in the form: var=value&var=value&var=value.
        * @param cookies A boolean value for loading or not the file 'cookie' (Default: Yes).
        * @param ua The UserAgent you want to set for this HTTP call (default: "Wiki++ Framework v0.2")
        * @return The HTML of the page.
        */
        static std::string post( std::string, std::string, std::string, bool cookies = 1, std::string bkd = "wget", std::string ua  = "Wiki++ Framework v0.2" );

      private:
        std::string backend;
        std::string useragent;
    };
  }
}

#endif

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

#ifndef WIKIPP_WIKI_LOGIN_H
#define WIKIPP_WIKI_LOGIN_H

// Temporary variable
#define HTTP_WGET

#include <iostream>
#include <string>

#include <boost/regex.hpp>

#include "../http/http.h"
#ifdef HTTP_WGET
  #include "../http/wget.h"
  #include "../libs/dati.h"
#endif
#include "../libs/convert.h"

namespace wikipp
{
  namespace wiki
  {
    /**
     * Class that manages the login to wikis.
     *
     * This class will completle take care of login in the wiki you need.
     * I want to remember you that<b> the url string HAVE TO BE in this
     * form: LANG.PROJ.TD (ie: en.wikipedia.org).</b>
     * This can be overturned by the logout function
     * @author Fabio Alessandro Locati
     */
    class login
    {
      public:
        /**
         * Function that allows you to log in
         *
         * @code
         * std::cout << wikipp::wiki::login::wikiLogin("en.wikipedia.org","USERNAME","PASSWORD") << std::endl;
         * @endcode
         *
         * @param url The url of the project (ie: en.wikipedia.org)
         * @param user The username that have to be used to login in the wiki-project
         * @param pass The password that have to be used to login in the wiki-project
         * @return 1 if the login succeded, 0 if the login not succeded
         */
        static bool wikiLogin( std::string url, std::string user, std::string pass );

        /**
        * Function that allows you to log in in API only
        *
        * @code
        * std::cout << wikipp::wiki::login::wikiLoginAPI("en.wikipedia.org","USERNAME","PASSWORD") << std::endl;
        * @endcode
        *
        * @param url The url of the project (ie: en.wikipedia.org)
        * @param user The username that have to be used to login in the wiki-project
        * @param pass The password that have to be used to login in the wiki-project
        * @return 1 if the login succeded, 0 if the login not succeded
        */
        static bool wikiLoginAPI( std::string url, std::string user, std::string pass );

        /**
        * Function that allows you to log in in HTTP only
        *
        * @code
        * std::cout << wikipp::wiki::login::wikiLoginHTTP("en.wikipedia.org","USERNAME","PASSWORD") << std::endl;
        * @endcode
        *
        * @param url The url of the project (ie: en.wikipedia.org)
        * @param user The username that have to be used to login in the wiki-project
        * @param pass The password that have to be used to login in the wiki-project
        * @return 1 if the login succeded, 0 if the login not succeded
        *
        * @bug Does not create the cookie = is a pointless function
        * @bug This is implemented only for Wget
        */
        static void wikiLoginHTTP( std::string url, std::string user, std::string pass );

        /**
         * Function that allows the system to create the wget's cookies
         *
         * @code
         * std::cout << wikipp::wiki::login::createCookie("en.wikipedia.org","SOURCE OF THE RESPONSE OF THE LOGIN PAGE") << std::endl;
         * @endcode
         *
         * @param url The url of the project (ie: en.wikipedia.org)
         * @param str The source of the response of the login page
         * @return 1 if the login succeded, 0 if the login not succeded
         */
        static bool createCookie( std::string url, std::string str );

        /**
         * Function that allows you to logout.
         *
         * @code
         * std::cout << wikipp::wiki::login::logout() << std::endl;
         * @endcode
         *
         * @return 1 if the login succeded, 0 if the login not succeded
         */
        static bool logout();
    };
  }
}
#endif

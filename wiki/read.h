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

#ifndef WIKIPP_WIKI_READ_H
#define WIKIPP_WIKI_READ_H

#include <iostream>
#include <string>

#include <boost/regex.hpp>

#include "../http/http.h"
#include "../libs/urlencode.h"

namespace wikipp
{
  namespace wiki
  {

    /**
    * Class that takes care about reading contents from a wiki site.
    *
    * @author Fabio Alessandro Locati
    *
    * @todo create the readPageTS
    * @todo create the readSourceTS
    */
    class read
    {
      public:

        /**
        * Function that allows you to read the page content in HTML
        *
        * @code
        * std::cout << wikipp::wiki::read::readPage( "en.wikipedia.org", "Main_Page", "API" ) << std::endl;
        * @endcode
        *
        * @param url The url of the project (ie: en.wikipedia.org).
        * @param page The name of the page to be read.
        * @param method It can be: "API" or "TS" (default: "API")
        * @return The HTML of the page.
        *
        * @see readPageAPI
        *
        * @bug TS is not valid at the moment
        */
        static std::string readPage( std::string, std::string, std::string method = "API" );

        /**
        * Function that allows you to read the page content in Wiki Syntax
        *
        * @code
        * std::cout << wikipp::wiki::read::readSource( "en.wikipedia.org", "Main_Page", "API" ) << std::endl;
        * @endcode
        *
        * @param url The url of the project (ie: en.wikipedia.org).
        * @param page The name of the page to be read.
        * @param method It can be: "API" or "TS" (default: "API")
        * @return The Wiki code of the page.
        *
        * @see readSourceAPI
        *
        * @bug TS is not valid at the moment
        */
        static std::string readSource( std::string, std::string, std::string method = "API" );

        /**
        * Function that allows you to read the page content in HTML
        *
        * @code
        * std::cout << wikipp::wiki::read::readPageAPI( "en.wikipedia.org", "Main_Page" ) << std::endl;
        * @endcode
        *
        * @param url The url of the project (ie: en.wikipedia.org).
        * @param page The name of the page to be read.
        * @return The HTML of the page.
        *
        * @see readPage
        */
        static std::string readPageAPI( std::string, std::string );

        /**
         * Function that allows you to read the page content in Wiki Syntax
         *
         * @code
         * std::cout << wikipp::wiki::read::readSourceAPI( "en.wikipedia.org", "Main_Page" ) << std::endl;
         * @endcode
         *
         * @param url The url of the project (ie: en.wikipedia.org).
         * @param page The name of the page to be read.
         * @return The Wiki code of the page.
         *
         * @see readSource
         */
        static std::string readSourceAPI( std::string, std::string );
    };
  }
}
#endif

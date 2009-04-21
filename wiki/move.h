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

#ifndef WIKIPP_WIKI_MOVE_H
#define WIKIPP_WIKI_MOVE_H

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
    * Class that takes care about moving pages.
    *
    * @author Fabio Alessandro Locati
    */
    class move
    {
      public:

        /**
        * Function that will return to you the XML page of the page containing informations
        *
        * @code
        * std::cout << wikipp::wiki::move::getData( "en.wikipedia.org" ) << std::endl;
        * @endcode
        *
        * @param site The url of the project (ie: en.wikipedia.org).
        * @return XML of with the data.
        */
        static std::string getData( std::string );

        /**
        * Function that will return the moveToken
        *
        * @code
        * std::cout << wikipp::wiki::move::returnMoveToken( "en.wikipedia.org" ) << std::endl;
        * @endcode
        *
        * @param site The url of the project (ie: en.wikipedia.org).
        * @return The moveToken without the ending "+\"
        */
        static std::string returnMoveToken( std::string );

        /**
        * Function that will return the moveToken
        *
        * @code
        * std::cout << wikipp::wiki::move::returnMoveToken( "en.wikipedia.org" ) << std::endl;
        * @endcode
        *
        * @param site The url of the project (ie: en.wikipedia.org).
        * @param from The inital page
        * @param to The ending page
        * @param reason Reason for moveing the page (Default: Wiki++.Bot)
        * @param moveTalk Move the talk page (Default: False)
        * @param noRedirect Don't create a redirect from the initial page to the ending page (Default: True)
        * @return Return what the API returns
        */
        static std::string movePage( std::string, std::string, std::string, std::string reason = "Wiki++.Bot", bool moveTalk = 0, bool noRedirect = 1 );
    };
  }
}
#endif

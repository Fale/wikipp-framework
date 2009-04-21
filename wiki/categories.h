/*
    Copyright (C) 2008, 2009 Fabio Alessandro Locati - fabiolocati@gmail.com

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

#ifndef WIKIPP_WIKI_CATEGORIES_H
#define WIKIPP_WIKI_CATEGORIES_H

#include <iostream>
#include <string>
#include <vector>

#include <boost/regex.hpp>

#include "../http/http.h"
#include "../libs/convert.h"

namespace wikipp
{
  namespace wiki
  {
    /**
     * Class that takes care about the images.
     *
     * @author Fabio Alessandro Locati
     */
    class categories
    {
      public:
        /**
        * Function that will return to you a list of every member in the category.
        *
        * @code
        * std::vector<std::string> vector = wikipp::wiki::categories::fetchMembers( "en.wikipedia.org", "Qt" );
        * for ( int c = 0; c < vector.size(); c++ )
        * {
        *   if ( vector[c] == "" )
        *     break;
        *   else
        *     std::cout << c + 1 << " " << vector[c] << std::endl;
        * }
        * @endcode
        *
        * @param site The url of the project (ie: en.wikipedia.org)
        * @param category The name of the category to be scanned
        * @param limit The maximum amount of results that will be returned (default: 500)
        * @param ns The namespace to be checked (default: all)
        * @return A list of every member in the category.
        *
        * @bug Maximum limit = 500 (5000 for bots)
        */
        static std::vector<std::string> fetchMembers( std::string, std::string, unsigned int limit = 500, unsigned int ns = 100 );

        /**
        * Function that will return to you the number of the elements of a category
        *
        * @code
        * std::cout << wikipp::wiki::categories::countMembers( "en.wikipedia.org", "Qt" ) << std::endl;
        * @endcode
        *
        * @param site The url of the project (ie: en.wikipedia.org)
        * @param category The name of the category to be scanned
        * @return The number of elements in the category.
        */
        static unsigned int countMembers( std::string, std::string );
    };
  }
}
#endif

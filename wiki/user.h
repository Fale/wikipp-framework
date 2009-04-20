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

#ifndef WIKIPP_WIKI_USER_H
#define WIKIPP_WIKI_USER_H

#include <iostream>
#include <string>

#include <boost/regex.hpp>

#include <http/http.h>
#include <libs/convert.h>

namespace wikipp
{
  namespace wiki
  {

    /**
     * Class that manages the users.
     *
     * @author Fabio Alessandro Locati
     * @todo Create a function that is able to count the crosswiki edits
     */
    class user
    {
      public:

        /**
         * Function that is able to list the edits from a user
         *
         * @code
         * std::cout << wikipp::wiki::edits::count( "en.wikipedia.org", "Fale" ) << std::endl;
         * @endcode
         *
         * @param url Link to the project home (ie: "en.wikipedia.org")
         * @param user Username's edits that have to be listed
         * @param limit Limit the query
         * @return List of edits made by the user
         *
         * @bug As it is now is useless and bugged.
         * @todo Make this function returning a matrix of values
         */
        static std::string editList(std::string, std::string, int limit = 5000);

        /**
         * Function that is able to count the edits
         *
         * @code
         * std::cout << wikipp::wiki::edits::count( "en.wikipedia.org", "Fale" ) << std::endl;
         * @endcode
         *
         * @param url Link to the project home (ie: "en.wikipedia.org")
         * @param user Username's edits that have to be counted
         * @return Number of edits made by the user
         */
        static int editCount( std::string, std::string );
    };
  }
}
#endif

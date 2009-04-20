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

#ifndef WIKIPP_WIKI_RELATEDPAGES_H
#define WIKIPP_WIKI_RELATEDPAGES_H

#include <iostream>
#include <string>

#include <boost/regex.hpp>

namespace wikipp
{
  namespace wiki
  {
    /**
    * Class that allows you to know the name of the talk page of a page and vice versa.
    *
    * @author Fabio Alessandro Locati
    */
    class relatedPages
    {
      public:
        /**
        * Function that returns you the name of the talk page of a given page.
        *
        * @code
        * std::cout << wikipp::wiki::relatedPages::toTalk( "Main Page" ) << std::endl;
        * @endcode
        *
        * @param page Name of the page.
        * @return Name of the talk page
        *
        * @todo i18n
        */
        static std::string toTalk( std::string );

        /**
        * Function that returns you the name of the page of a given talk page.
        * Names must be in english like NameSpace_talk:NamePage or Talk:NamePage.
        *
        * @code
        * std::cout << wikipp::wiki::relatedPages::toPage( "Talk:Main Page" ) << std::endl;
        * @endcode
        *
        * @param talk Name of the talk page.
        * @return Name of the page
        *
        * @todo i18n
        */
        static std::string toPage( std::string );
    };
  }
}
#endif

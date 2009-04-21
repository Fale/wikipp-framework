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

#ifndef WIKIPP_WIKI_EDITTOKEN_H
#define WIKIPP_WIKI_EDITTOKEN_H

#include <iostream>
#include <string>

#include <boost/regex.hpp>

#include "../http/http.h"

namespace wikipp
{
  namespace wiki
  {
    /**
     * Class that manages the edittokens.
     *
     * This class will completle take care of returning the edittoken.
     * I want to remember you that<b> the url string HAVE TO BE in this
     * form: LANG.PROJ.TD (ie: en.wikipedia.org).</b>
     * @author Fabio Alessandro Locati
     */
    class edittoken
    {
      public:
        /**
         * Function that will return to you the edittoken (<b>It does not return the complete
         * edittoken, but it will return the string without the +\\</b>).
         *
         * @code
         * std::cout << wikipp::wiki::edittoken::returnEditToken( "en.wikipedia.org" ) << std::endl;
         * @endcode
         *
         * @param url The url of the project (ie: en.wikipedia.org)
         * @param complete Do you want a complete edittoken or only the first piece? (default: complete)
         *
         * @return The edittoken (<b>If you have chosed the complete edittoken, you'll get it, if you have
         * chosed the not complete edittoken you will have the string without the +\\ at the end</b>).
         */
        static std::string returnEditToken( std::string, bool complete = 1 );
    };
  }
}
#endif

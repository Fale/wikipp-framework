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

#ifndef WIKIPP_WIKI_RELATEDPAGES_CPP
#define WIKIPP_WIKI_RELATEDPAGES_CPP

#include "relatedpages.h"

namespace wikipp
{
  namespace wiki
  {
    std::string relatedPages::toTalk( std::string page )
    {
      boost::regex regex( "(.*?):(.*?)" );
      boost::smatch match;
      boost::regex_match( page, match, regex );
      std::string ns( match[1] );
      #ifdef DEBUG_LIB
        std::cout << "The discussion page of " << page << " is " << out << std::endl;
      #endif
      if ( ns != "" )
        return ns + "_talk:" + match[2];
      else
        return "Talk:" + page;
    }

    std::string relatedPages::toPage( std::string talk )
    {
      boost::regex regex( "(.*?)_talk:(.*?)" );
      boost::smatch match;
      boost::regex_match( talk, match, regex );
      std::string ns( match[1] );
      regex = "(.*?):(.*?)";
      boost::regex_match( talk, match, regex );
      #ifdef DEBUG_LIB
      std::cout << "The main page of " << talk << " is " << out << std::endl;
      #endif
      if ( ns != "" )
        return ns + ":" + match[2];
      else
        return match[2];
    }
  }
}
#endif

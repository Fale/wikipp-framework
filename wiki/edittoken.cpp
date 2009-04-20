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

#ifndef WIKIPP_WIKI_EDITTOKEN_CPP
#define WIKIPP_WIKI_EDITTOKEN_CPP

#include "edittoken.h"

namespace wikipp
{
  namespace wiki
  {
    std::string edittoken::returnEditToken( std::string url, bool complete )
    {
      std::string uri( "w/api.php?action=query&prop=info|revisions&intoken=edit&format=xml&titles=Main_Page" );
      std::string data( http::http::get( url, uri ) );

      boost::regex pat( "(.*) edittoken=\"(.*?)\\+\\\\\"(.*)" );
      boost::smatch matches;
      boost::regex_match( data, matches, pat );
      if ( complete == 1 )
        return matches[2] + "%2B%5C";
      else
        return matches[2];
    }
  }
}
#endif

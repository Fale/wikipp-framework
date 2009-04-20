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

#ifndef WIKIPP_WIKI_MOVE_CPP
#define WIKIPP_WIKI_MOVE_CPP

#include "move.h"

namespace wikipp
{
  namespace wiki
  {
    std::string move::getData( std::string site )
    {
      std::string uri( "w/api.php?action=query&format=xml&prop=info&intoken=move&titles=Main%20Page" );
      return http::http::get( site, uri );
    }

    std::string move::returnMoveToken( std::string site )
    {
      std::string data ( getData( site ) );
      boost::regex pat( "(.*) movetoken=\"(.*?)\\+\\\\\"(.*)" );
      boost::smatch matches;
      boost::regex_match( data, matches, pat );
      return matches[2];
    }

    std::string move::movePage( std::string site, std::string from, std::string to, std::string reason, bool moveTalk, bool noRedirect )
    {
      std::string post( "from=" + libs::urlEncode::urlencode( from ) + "&to=" + libs::urlEncode::urlencode( to ) + "&reason=" + libs::urlEncode::urlencode( reason ) + "&token=" + returnMoveToken( site ) + "%2B%5C" );

      if ( moveTalk == 1 )
        post += "&movetalk";
      if ( noRedirect == 0 )
        post += "&noredirect";
      return http::http::post ( site, "w/api.php?action=move&format=xml", post );
    }
  }
}
#endif

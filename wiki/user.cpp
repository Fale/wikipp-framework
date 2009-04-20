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

#ifndef WIKIPP_WIKI_USER_CPP
#define WIKIPP_WIKI_USER_CPP

#include "user.h"
namespace wikipp
{
  namespace wiki
  {
    std::string user::editList(std::string url, std::string user, int limit )
    {
      std::string uri( "w/api.php?action=query&list=usercontribs&uclimit=" + toString( limit ) + "&ucuser=" + user );
      return http::http::get( url, uri );
    }

    int user::editCount( std::string url, std::string user )
    {
      std::string uri( "w/api.php?action=query&list=users&usprop=editcount&ususers=" + user );
      std::string response( http::http::get( url, uri ) );
      boost::regex pat( "(.*)editcount=\"(.*)\"(.*)" );
      boost::smatch matches;
      boost::regex_match( response, matches, pat );
      return toInt( matches[2] );
    }
  }
}
#endif

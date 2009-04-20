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

#ifndef WIKIPP_WIKI_CATEGORIES_CPP
#define WIKIPP_WIKI_CATEGORIES_CPP

#include <wiki/categories.h>

namespace wikipp
{
  namespace wiki
  {
    std::vector<std::string> categories::fetchMembers( std::string site, std::string category, unsigned int limit, unsigned int ns )
    {
      std::vector<std::string> ret;
      boost::regex rx;
      std::string uri ( "w/api.php?action=query&format=xml&list=categorymembers&cmlimit=" + toString( limit ) + "&cmtitle=Category:" + category );
      std::string data ( http::http::get( site, uri ) );
      if ( ns == 100 )
        rx = "(.*?)title=\"(.*?)\"(.*)";
      else
        rx = "(.*?)ns=\"" + toString( ns ) + "\" title=\"(.*?)\"(.*)";
      boost::smatch matches;
      for ( unsigned int c = 0; c < limit; c++ )
      {
        boost::regex_match( data, matches, rx );
        if ( matches[2] == "" )
          break;
        else
          ret.push_back( matches[2] );
        data = matches[3];
      }
      return ret;
    }

    unsigned int categories::countMembers( std::string site, std::string category )
    {
      std::string uri ( "w/api.php?action=query&format=xml&prop=categoryinfo&titles=Category:" + category );
      std::string data ( http::http::get( site, uri ) );
      boost::regex rx( "(.*?)size=\"(\\d*)\"(.*)" );
      boost::smatch matches;
      boost::regex_match( data, matches, rx );
      return toInt( matches[2] );
    }
  } //namespace wiki
} //namespace wikipp
#endif

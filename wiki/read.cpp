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

#ifndef WIKIPP_WIKI_READ_CPP
#define WIKIPP_WIKI_READ_CPP

#include "read.h"

namespace wikipp
{
  namespace wiki
  {
    std::string read::readPage( std::string url, std::string page, std::string method )
    {
      if( method == "API" )
        return readPageAPI( url, page );
    }

    std::string read::readSource( std::string url, std::string page, std::string method )
    {
      if( method == "API" )
        return readSourceAPI( url, page );
    }

    std::string read::readPageAPI( std::string url, std::string page )
    {
      std::string uri( "w/api.php?action=parse&format=xml&page=" + page );
      std::string response( http::http::get( url, uri ) );
      boost::regex pat( "(.*)<text>(.*)</text>(.*)" );
      boost::smatch matches;
      boost::regex_match( response, matches, pat );
      return matches[2] + "\n";
    }

    std::string read::readSourceAPI( std::string url, std::string page )
    {
      std::string uri( "w/index.php?title=" + page + "&action=raw" );
      return libs::urlEncode::urlencode( http::http::get( url, uri ) );
    }
  }
}
#endif

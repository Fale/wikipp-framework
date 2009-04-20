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

#ifndef WIKIPP_EXTENDED_EARTHQUAKE_CPP
#define WIKIPP_EXTENDED_EARTHQUAKE_CPP

#include <extended/earthquake.h>

namespace wikipp
{
  namespace extended
  {
    earthquake::earthquake(){}

    earthquake::earthquake( std::string loc)
    {
      location = loc;
    }

    void earthquake::setLocation( std::string loc )
    {
      location = loc;
    }

    std::string earthquake::getLocation()
    {
      return location;
    }

    std::vector<std::vector<std::string>> earthquake::fetchData()
    {
      //          std::string code ( wikipp::http::http::get( "emsc-csem.org", "index.php?page=current&sub=list", 0 ) );
    }

    std::vector<std::string> earthquake::getLine()
    {
      std::string code ( wikipp::http::http::get( "emsc-csem.org", "index.php?page=current&sub=list", 0 ) );
      std::vector<std::string> ret;
      do
      {
        boost::regex pat( "(.*)<tr (.*)>(.*)</tr>(.*)" );
        boost::smatch matches;
        boost::regex_match( code, matches, pat );
        ret.push_back( matches[3] );
      } while ( matches[4] );
      return ret;
    }
  }
}
#endif


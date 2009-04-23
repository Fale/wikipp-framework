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

#ifndef WIKIPP_EXTENDED_INDEX_CPP
#define WIKIPP_EXTENDED_INDEX_CPP

#include "index.h"

namespace wikipp
{
  namespace extended
  {
    std::string index::yahoo( std::string index )
    {
      std::string data( http::http::get( "it.finance.yahoo.com","q?s=" + index ) );
      std::string image;
      std::string colour;
      std::string sign;

      boost::regex pat( "(.*?)<big><b><span id=\"(.*?)\">(.*?)</span></b></big>(.*?)" );
      boost::smatch matches;
      boost::regex_match( data, matches, pat );

      std::string val( matches[3] );

      boost::regex upR( "(.*?)src=\"http://us.i1.yimg.com/us.yimg.com/i/us/fi/03rd/(.*?)\"(.*?)" );
      boost::regex_match( data, matches, upR );

      if ( matches[2] == "down_r.gif" )
      {
        image = "[[Immagine:Red_Arrow_Down.svg|10px]]";
        colour = "red";
        sign = "- ";
      }
       else
        if ( matches[2] == "up_g.gif" )
        {
          image = "[[Immagine:Green_Arrow_Up.svg|10px]]";
          colour = "green";
          sign = "+ ";
        }

      boost::regex valR( "(.*?)<b class=\"(.*)\">(.*?)</b></span> <span id=\"(.*?)\"><b class=\"(.*?)\"> \\((.*?)\\)</b>(.*?)" );
      boost::regex_match( data, matches, valR );

      return "|'''" + val + "'''\n|<span style=color:" + colour + ">" + image + " " + matches[3] + "</span>\n|<span style=color:" + colour + ">" + sign + matches[6] + "</span>\n";
    }
  }
}
#endif

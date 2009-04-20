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

#ifndef WIKIPP_HTTP_WGET_CPP
#define WIKIPP_HTTP_WGET_CPP

#include "wget.h"

namespace wikipp
{
  namespace http
  {
    std::string wget::getRaw( std::string url, std::string link, bool cookies, std::string ua )
    {
      std::string wgcom;
      if ( cookies )
        wgcom = "wget \"http://" + url + "/" + link + "\" -o log -O temp --save-headers --load-cookies=cookie --user-agent=\"" + ua + "\"";
      else
        wgcom = "wget \"http://" + url + "/" + link + "\" -o log -O temp --save-headers --user-agent=\"" + ua + "\"";
      return wget::procedure( wgcom );
    }

    std::string wget::get( std::string url, std::string link, bool cookies, std::string ua )
    {
      std::string wgcom;
      if ( cookies )
        wgcom = "wget \"http://" + url + "/" + link + "\" -o log -O temp --load-cookies=cookie --user-agent=\"" + ua + "\"";
      else
        wgcom = "wget \"http://" + url + "/" + link + "\" -o log -O temp --user-agent=\"" + ua + "\"";
      return wget::procedure( wgcom );
    }

    std::string wget::postRaw( std::string url, std::string link, std::string postValues, bool cookies, std::string ua )
    {
      std::string wgcom;
      if ( cookies )
        wgcom = "wget \"http://" + url + "/" + link + "\" -o log -O temp --save-headers --load-cookies=cookie --post-data '" + postValues + "' --user-agent=\"" + ua + "\"";
      else
        wgcom = "wget \"http://" + url + "/" + link + "\" -o log -O temp --save-headers --post-data '" + postValues + "' --user-agent=\"" + ua + "\"";
      return wget::procedure( wgcom );
    }

    std::string wget::post( std::string url, std::string link, std::string postValues, bool cookies, std::string ua )
    {
      std::string wgcom;
      if ( cookies )
        wgcom = "wget \"http://" + url + "/" + link + "\" -o log -O temp --load-cookies=cookie --post-data '" + postValues + "' --user-agent=\"" + ua + "\"";
      else
        wgcom = "wget \"http://" + url + "/" + link + "\" -o log -O temp --post-data '" + postValues + "' --user-agent=\"" + ua + "\"";
      return wget::procedure( wgcom );
    }

    std::string wget::procedure( std::string wgcom )
    {
      unsigned int errors;
      #ifdef DEBUG_LIB
      std::cout << wgcom;
      #endif
      std::string str;
      errors = std::system ( wgcom.c_str() );
      std::stringstream sstr;
      std::ifstream file( "temp" );
      sstr << file.rdbuf();
      file.close();
      str = sstr.str();
      errors = errors + std::system ( "rm log" );
      errors = errors + std::system ( "rm temp" );
      #ifdef DEBUG_LIB
      std::cout << errors;
      #endif
      return str;
    }
  }
}
#endif

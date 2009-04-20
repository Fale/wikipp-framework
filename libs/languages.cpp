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

#ifndef WIKIPP_LIBS_LANGUAGES_CPP
#define WIKIPP_LIBS_LANGUAGES_CPP

#include <libs/languages.h>

namespace wikipp
{
  namespace libs
  {
    std::string i18n::translate( std::string str, std::string lang = "en" )
    {
      std::stringstream sstr;
      lang = lang + ".lang";

      std::ifstream file( toChar( lang ) );
      sstr << file.rdbuf();
      std::string string( sstr.str() );
      file.close();

      boost::regex regex( "(.*)" + urlEncode::urlencode( str ) + "=(.*?);(.*)" );
      boost::smatch match;
      boost::regex_match( string, match, regex );

      #ifdef DEBUG_LIB
      std::cout << std::endl << "i18n( " << urlEncode::urlencode( str ) << " ) = " << match[2] << std::endl;
      #endif

      return match[2];
    }
  }
}


#endif

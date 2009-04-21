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

#ifndef WIKIPP_LIBS_URLENCODE_CPP
#define WIKIPP_LIBS_URLENCODE_CPP

#include "urlencode.h"

namespace wikipp
{
  namespace libs
  {

    bool urlEncode::isAlphaNum( const char s )
    {
      if (  ( static_cast<unsigned char>( s ) > 47 && static_cast<unsigned char>( s ) < 58 ) || ( static_cast<unsigned char>( s ) > 64 && static_cast<unsigned char>( s ) < 91 ) || ( static_cast<unsigned char>( s ) > 96 && static_cast<unsigned char>( s ) < 123 ) )
        return 1;
      else
        return 0;
    }

    std::string urlEncode::complete( const std::string &s )
    {
      std::string result;
      for ( unsigned i = 0; i < s.length(); ++i )
      {
        result += "%";
        result += hexAlphabet[ static_cast<unsigned char>( s[i] ) / 16 ];
        result += hexAlphabet[ static_cast<unsigned char>( s[i] ) % 16 ];
      }
      return result;
    }

    std::string urlEncode::minimal( const std::string &s )
    {
      std::string result;
      std::string temp;

      for ( unsigned i = 0; i < s.length(); ++i )
      {
        if ( urlEncode::isAlphaNum( s[i] ) )
        {
          result += s[i];
        }
        else
        {
          result += "%";
          result += hexAlphabet[ static_cast<unsigned char>( s[i] ) / 16 ];
          result += hexAlphabet[ static_cast<unsigned char>( s[i] ) % 16 ];
        }
      }
      return result;
    }

    std::string urlEncode::urlencode( const std::string &s, bool complete )
    {
      std::string result;
      std::string temp;
      for ( unsigned i = 0; i < s.length(); ++i )
      {
        if ( urlEncode::isAlphaNum( s[i] ) && complete == 0 )
        {
          result += s[i];
        }
        else
        {
          result += "%";
          result += hexAlphabet[ static_cast<unsigned char>( s[i] ) / 16 ];
          result += hexAlphabet[ static_cast<unsigned char>( s[i] ) % 16 ];
        }
      }
      return result;
    }
  }
}

#endif

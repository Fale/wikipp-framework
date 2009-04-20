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

#ifndef WIKIPP_LIBS_URLENCODE_H
#define WIKIPP_LIBS_URLENCODE_H

#include <string>

const char hexAlphabet[] = "0123456789ABCDEF";

namespace wikipp
{
  namespace libs
  {
    /**
    * Class that urlencodes strings
    *
    * @author Fabio Alessandro Locati
    */
    class urlEncode
    {
      public:
        /**
        * Function to control if a character is alphanumeric or not.
        *
        * @param s The character to be checked.
        * @return 1 if the character is alphanumeric, 0 if it is not.
        *
        * @bug deleted, to be repristinated
        */
        static bool isAlphaNum( const char );

        /**
        * Function that allows you to urlencode completly a string.
        *
        * This function, differently from minimal() allows
        * you to urlencoding completly the string. In fact this function will, also,
        * urlEncode the numbers and the strings.
        *
        * @param s The string to be urlEncoded
        * @return the string urlEncoded
        *
        * @see minimal(), urlencode()
        *
        * @deprecated This will soon be dropped. Please use wikipp::libs::urlEncode::urlencode( std::string, [bool] ).
        */
        static std::string complete( const std::string& );

        /**
        * Function that allows you to urlencode a string.
        *
        * @param s The string to be urlEncoded
        * @return the string urlEncoded
        *
        * @see complete(), urlencode()
        *
        * @deprecated This will soon be dropped. Please use wikipp::libs::urlEncode::urlencode( std::string, [bool] ).
        */
        static std::string minimal( const std::string& );

        /**
        * Function that allows you to urlencode a string.
        *
        * This function allows you to choose (throughout the boolean parameter complete)
        * if you want a complete urlencode (in this case every single character will be
        * urlencoded, even numbers and letters) or a minimal urlencode (in this case only
        * the characters not alphanumerics will be encoded).
        *
        * @param s The string to be urlEncoded
        * @param complete Boolean value to decide whether or not the urlencode has to be complete. Default: 0.
        * @return The string urlEncoded
        */
        static std::string urlencode( const std::string&, bool complete = 0 );
    };
  }
}

#endif

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

#ifndef WIKIPP_LIBS_LANGUAGES_H
#define WIKIPP_LIBS_LANGUAGES_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <boost/regex.hpp>

#include "convert.h"
#include "urlencode.h"

/**
* Function that allows you to create multilanguage apps
*
* @param str The string to be translate
* @param lang The language that you want, default: English
* @return 1 if the login succeded, 0 if the login not succeded
*/
namespace wikipp
{
  namespace libs
  {
    class i18n
    {
      public:
        static std::string translate( std::string, std::string );
    };
  }
}

#endif

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

#ifndef WIKIPP_LIBS_PRGDATA_CPP
#define WIKIPP_LIBS_PRGDATA_CPP

#include <libs/prgdata.h>

namespace wikipp
{
  namespace libs
  {

    std::string prgdata::getUsername()
    {
      std::string string;
      std::stringstream sstr;

      std::ifstream file( "config" );
      sstr << file.rdbuf();
      string = sstr.str();
      file.close();

      boost::regex regex( "(.*)username=(.*?);(.*)" );
      boost::smatch match;
      boost::regex_match( string, match, regex );

      #ifdef DEBUG_LIB
        std::cout << std::endl << "Username = " << match[2] << std::endl;
      #endif

      return match[2];
    }

    std::string prgdata::getPassword()
    {
      std::string string;
      std::stringstream sstr;

      std::ifstream file( "config" );
      sstr << file.rdbuf();
      string = sstr.str();
      file.close();

      boost::regex regex( "(.*)password=(.*?);(.*)" );
      boost::smatch match;
      boost::regex_match( string, match, regex );

      #ifdef DEBUG_LIB
        std::cout << std::endl << "Password = " << match[2] << std::endl;
      #endif

      return match[2];
    }

    std::string prgdata::getProject()
    {
      std::string string;
      std::stringstream sstr;

      std::ifstream file( "config" );
      sstr << file.rdbuf();
      string = sstr.str();
      file.close();

      boost::regex regex( "(.*)project=(.*?);(.*)" );
      boost::smatch match;
      boost::regex_match( string, match, regex );

      #ifdef DEBUG_LIB
        std::cout << std::endl << "Project = " << match[2] << std::endl;
      #endif

      return match[2];
    }

    std::string prgdata::getPage()
    {
      std::string string;
      std::stringstream sstr;

      std::ifstream file( "config" );
      sstr << file.rdbuf();
      string = sstr.str();
      file.close();

      boost::regex regex( "(.*)page=(.*?);(.*)" );
      boost::smatch match;
      boost::regex_match( string, match, regex );

      #ifdef DEBUG_LIB
        std::cout << std::endl << "Page = " << match[2] << std::endl;
      #endif

      return match[2];
    }

    std::string prgdata::getTimeZone()
    {
      std::string string;
      std::stringstream sstr;

      std::ifstream file( "config" );
      sstr << file.rdbuf();
      string = sstr.str();
      file.close();

      boost::regex regex( "(.*)timezone=(.*?);(.*)" );
      boost::smatch match;
      boost::regex_match( string, match, regex );

      #ifdef DEBUG_LIB
      std::cout << std::endl << "Time Zone = " << match[2] << std::endl;
      #endif

      return match[2];
    }

    std::string prgdata::getLanguage()
    {
      std::string string;
      std::stringstream sstr;

      std::ifstream file( "config" );
      sstr << file.rdbuf();
      string = sstr.str();
      file.close();

      boost::regex regex( "(.*)language=(.*?);(.*)" );
      boost::smatch match;
      boost::regex_match( string, match, regex );

      #ifdef DEBUG_LIB
      std::cout << std::endl << "Language = " << match[2] << std::endl;
      #endif

      return match[2];
    }

    std::string prgdata::getVariable(std::string variable)
    {
      std::string string;
      std::stringstream sstr;

      std::ifstream file( "config" );
      sstr << file.rdbuf();
      string = sstr.str();
      file.close();

      boost::regex regex( "(.*)" + variable + "=(.*?);(.*)" );
      boost::smatch match;
      boost::regex_match( string, match, regex );

      #ifdef DEBUG_LIB
        std::cout << std::endl << variable << " = " << match[2] << std::endl;
      #endif

      return match[2];
    }

  }
}

#endif

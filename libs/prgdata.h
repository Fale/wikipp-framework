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

#ifndef WIKIPP_LIBS_PRGDATA_H
#define WIKIPP_LIBS_PRGDATA_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <boost/regex.hpp>

namespace wikipp
{
  namespace libs
  {

    /**
     * Class that manage data written in a config file.
     *
     * Can be very useful in a lot of ways
     * An example of a config file is
     * @ingroup libs
     * @code
     * username=USERNAME;
     * password=PASSWORD;
     * project=PROJECT_NAME;
     * page=PAGE THAT THE BOT WILL HAVE TO USE;
     * timezone=TIMEZONE[FORM: CONTINENT/CITY];
     * VARNAME=VARDATA;
     * @endcode
     * All these things are completle up to the programmer.
     * <b> No one of these are mandatory. </b>
     * @author Fabio Alessandro Locati
     */
    class prgdata
    {
      public:

        /**
        * Function that take care of managing the username.
        *
        * @code
        * std::cout << wikipp::libs::prgdata::getUsername() << std::endl;
        * @endcode
        *
        * @return The username setted in the config file
        */
        static std::string getUsername();

        /**
        * Function that take care of managing the password.
        *
        * @code
        * std::cout << wikipp::libs::prgdata::getPassword() << std::endl;
        * @endcode
        *
        * @return The password setted in the config file
        */
        static std::string getPassword();

        /**
        * Function that take care of managing the project name.
        *
        * @code
        * std::cout << wikipp::libs::prgdata::getProject() << std::endl;
        * @endcode
        *
        * @return The project name setted in the config file
        */
        static std::string getProject();

        /**
        * Function that take care of managing the page.
        *
        * @code
        * std::cout << wikipp::libs::prgdata::getPage() << std::endl;
        * @endcode
        *
        * @return The page setted in the config file
        */
        static std::string getPage();

        /**
        * Function that take care of managing the Time Zone.
        *
        * @code
        * std::cout << wikipp::libs::prgdata::getTimeZone() << std::endl;
        * @endcode
        *
        * @return The Time Zone setted in the config file
        */
        static std::string getTimeZone();

        /**
        * Function that take care of managing the Language.
        *
        * @code
        * std::cout << wikipp::libs::prgdata::getLanguage() << std::endl;
        * @endcode
        *
        * @return The Language setted in the config file
        */
        static std::string getLanguage();

        /**
        * Function that take care of managing a variable define by the user.
        *
        * @code
        * std::cout << wikipp::libs::prgdata::getVariable( "name" ) << std::endl;
        * @endcode
        *
        * @param variable Variable usefull to pass the variable name to be readen from the config file
        * @return The value of the variable setted in the config file with the name indicated as imput
        */
        static std::string getVariable( std::string );
    };
  }
}

#endif

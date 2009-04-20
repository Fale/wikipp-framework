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

#ifndef WIKIPP_LIBS_DATI_H
#define WIKIPP_LIBS_DATI_H

#include <vector>

#include "boost/date_time/local_time/local_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"

#include <libs/convert.h>

namespace wikipp
{
  namespace libs
  {

    /**
     * Class that return the date connected information.
     *
     * @author Fabio Alessandro Locati
     */
    class dati
    {
      public:

        /*
         * Function that returns the seconds since Epoch.
         *
         * @code
         * int str;
         * str = wikipp::libs::dati::sinceEpoch( std::string tz );
         * std::cout << str << std::endl;
         * @endcode
         * @code
         * int str;
         * str = wikipp::libs::dati::sinceEpoch();
         * std::cout << str << std::endl;
         * @endcode
         * @param tz The timezone in the form "Continent/City". By default is setted on London.
         * @return The number of seconds since Epoch.
         */
        //static int sinceEpoch( std::string );
        /**
        * Function that returns the seconds since Epoch (1,1,1970).
        *
        * @code
        * std::cout << wikipp::libs::dati::sinceEpoch() << std::endl;
        * @endcode
        * @return The number of seconds since Epoch.
        */
        static int sinceEpoch();

        /*
         * Function that returns the seconds since Epoch.
         *
         * @code
         * std::vector<int> str;
         * str = wikipp::libs::dati::dateTime( std::string tz );
         * std::cout << "Seconds" << str[0] << std::endl;
         * std::cout << "Minutes" << str[1] << std::endl;
         * std::cout << "Hours" << str[2] << std::endl;
         * std::cout << "Day" << str[3] << std::endl;
         * std::cout << "Month" << str[4] << std::endl;
         * std::cout << "Year" << str[5] << std::endl;
         * @endcode
         * @code
         * std::vector<int> str;
         * str = wikipp::libs::dati::dateTime();
         * std::cout << "Seconds" << str[0] << std::endl;
         * std::cout << "Minutes" << str[1] << std::endl;
         * std::cout << "Hours" << str[2] << std::endl;
         * std::cout << "Day" << str[3] << std::endl;
         * std::cout << "Month" << str[4] << std::endl;
         * std::cout << "Year" << str[5] << std::endl;
         * @endcode
         * @param tz The timezone in the form "Continent/City". By default is setted on London.
         * @return The actual date and time
         * @return [0] = seconds [0-59]
         * @return [1] = minutes [0-59]
         * @return [2] = hours [0-23]
         * @return [3] = day [1-31]
         * @return [4] = month [1-12]
         * @return [5] = year [4 digit]
         */
	      //static std::vector<int> dateTime( std::string );
        /**
        * Function that returns the seconds since Epoch.
        *
        * @code
        * std::vector<int> str;
        * str = wikipp::libs::dati::dateTime();
        * std::cout << "Seconds" << str[0] << std::endl;
        * std::cout << "Minutes" << str[1] << std::endl;
        * std::cout << "Hours" << str[2] << std::endl;
        * std::cout << "Day" << str[3] << std::endl;
        * std::cout << "Month" << str[4] << std::endl;
        * std::cout << "Year" << str[5] << std::endl;
        * @endcode
        *
        * @return The actual date and time
        * @return [0] = seconds [0-59]
        * @return [1] = minutes [0-59]
        * @return [2] = hours [0-23]
        * @return [3] = day [1-31]
        * @return [4] = month [1-12]
        * @return [5] = year [4 digit]
        */
        static std::vector<int> dateTime();

        /*
        * Function that returns the date in the standard form ( YYYYMMDD ).
        *
        * @code
        * std::string str( wikipp::libs::dati::standardDate( "Europe/Rome" ) );
        * std::cout << str << std::endl;
        * @endcode
        * @code
        * std::string str( wikipp::libs::dati::standardDate() );
        * std::cout << str << std::endl;
        * @endcode
        * @param tz The timezone in the form "Continent/City". By default is setted on Europe/London.
        * @return The actual date in the YYYYMMDD format
        */
        //static std::string standardDate( std::string );

        /*
        * Function that returns the date in the standard form ( DD/MM/YYYY ).
        *
        * @code
        * std::string str( wikipp::libs::dati::date( "Europe/Rome", "-" ) );
        * std::cout << str << std::endl;
        * @endcode
        * @code
        * std::string str( wikipp::libs::dati::date( "Europe/Rome" ) );
        * std::cout << str << std::endl;
        * @endcode
        * @code
        * std::string str( wikipp::libs::dati::date() );
        * std::cout << str << std::endl;
        * @endcode
        * @param tz The timezone in the form "Continent/City". By default is setted on Europe/London.
        * @param delimitator Is the delimitator between the Day, Month and year.
        * @return The actual date in the DD/MM/YYYY format
        */
//        static std::string date( std::string tz , std::string );

        /*
        * Function that returns the time in the standard form ( HH:MM:SS ).
        *
        * @code
        * std::string str( wikipp::libs::dati::time( "Europe/Rome", "." ) );
        * std::cout << str << std::endl;
        * @endcode
        * @code
        * std::string str( wikipp::libs::dati::time( "Europe/Rome" ) );
        * std::cout << str << std::endl;
        * @endcode
        * @code
        * std::string str( wikipp::libs::dati::time() );
        * std::cout << str << std::endl;
        * @endcode
        * @param tz The timezone in the form "Continent/City". By default is setted on Europe/London.
        * @param delimitator Is the delimitator between the Hours, Minutes, and Seconds.
        * @return The actual date in the HH:MM:SS format
        */
/*        static std::string wikipp::libs::dati::time( std::string tz = "Europe/London", std::string delimitator = ":" )
        {
          std::vector<int> time = wikipp::libs::dati::dateTime(tz);
          return time[2] << delimitator << time[1] << delimitator << time[0];
        }
*/
        /*
        * Function that returns the time in the form you want.
        *
        * @param tz The timezone in the form "Continent/City". By default is setted on Europe/London.
        * @param format Is the format of the date that will be returned.
        * @param gap Gap between now and the date you want
        * @return The actual date.
        */
//        static std::string time( std::string, std::string, std::string, std::string );
    };
  }
}

#endif

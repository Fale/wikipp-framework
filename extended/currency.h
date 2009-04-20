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

#ifndef WIKIPP_EXTENDED_CURRENCY_H
#define WIKIPP_EXTENDED_CURRENCY_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

#include <boost/regex.hpp>

#include <http/http.h>

namespace wikipp
{
  namespace extended
  {

    /**
    * Class that manage currency exchange
    *
    * @author Fabio Alessandro Locati
    */
    class currency
    {
      public:
        std::string yahoo( std::string, std::string );
        std::string yahooBotB( std::string, std::string );
        void savefile( std::string currencyfrom = "" );

      private:
        /**
        * Function that takes care of fetching the data.
        *
        * @code
        * std::vector<std::string> data;
        * strt = wikipp::extended::currency::fetchNewData( "EUR", ""USD );
        * std::cout << strt << std::endl;
        * @endcode
        * @param currencyfrom String of the first currency.
        * @param currencyto String of the second currency.
        * @return The actual data
        * @return [0] = Value (form: 1.321,89)
        * @return [1] = Thousands (1 in the previous case)
        * @return [2] = Units (321 in the previous case)
        * @return [3] = Decimals (89 in the previous case)
        */
        std::vector<std::string> fetchNewData( std::string, std::string );

        /**
        * @bug Prev[2] returns weird things
        */
        std::vector<std::string> fetchOldData( std::string, std::string, bool inverted = 0 );
        std::string compare( std::vector<std::string>, std::vector<std::string> );
        std::vector<std::string> errorManagerBotB( std::string, std::string );
        std::stringstream stream;
        std::string bkpfile;
    };
  }
}
#endif

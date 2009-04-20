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

#ifndef WIKIPP_EXTENDED_EARTHQUAKE
#define WIKIPP_EXTENDED_EARTHQUAKE

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
    * Class that manage earthquakes
    *
    * @author Fabio Alessandro Locati
    */
    class earthquake
    {
      public:
        earthquake();
        earthquake( std::string );

        void setLocation( std::string );
        std::string getLocation();
        std::vector<std::vector<std::string>> fetchData();
        std::vector<std::string> getLine();

      private:
        std::string location;
    };
  }
}
#endif


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

#ifndef WIKIPP_LIBS_COMMANDLINE_H
#define WIKIPP_LIBS_COMMANDLINE_H

namespace wikipp
{
  namespace libs
  {
    /**
    * Class that semplify the command line parameters managment
    *
    * @author Fabio Alessandro Locati
    */
    class commandLine
    {
      public:
        static std::string value( std::string, std::string );
    };
  }
}

#endif

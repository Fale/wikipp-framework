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

#ifndef WIKIPP_LIBS_CONFIG
#define WIKIPP_LIBS_CONFIG

#ifdef DEBUG
  std::cout << std::endl << "Using DEBUG mode" << std::endl;
  #define DEBUG_LIB
  #define DEBUG_PRG
#endif

#ifdef WIKIMEDIA
  #ifdef DEBUG_LIB
    std::cout << std::endl << "Using WIKIMEDIA mode" << std::endl;
  #endif
  #define HTTP_WGET
  #define WRITE_HTTP
#endif

#endif

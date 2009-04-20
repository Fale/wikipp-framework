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

#ifndef WIKIPP_LIBS_CONVERT
#define WIKIPP_LIBS_CONVERT

#include <cstdlib>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>


/**
* Function that converts a string to int
*
* @code
* int var;
* var = toInt( "123" );
* std::cout << var << std::endl;
* @endcode
*
* @param t variable to be converted in int
* @return An int
*/
template <class T>
inline int toInt ( const T& t )
{
  int out;
  std::stringstream ss;
  ss << t;
  ss >> out;
  return out;
}

/**
* Function that converts a char to string
*
* @code
* char var;
* var = toChar( "hello world" );
* std::cout << var << std::endl;
* @endcode
*
* @param t variable to be converted in char
* @return A char
*/
template <class T>
inline const char* toChar ( const T& t )
{
  std::stringstream ss;
  ss << t;
  std::string str ( ss.str() );
  return str.c_str();
}

/**
* Function that converts variables to string
*
* @code
* std::string var( toString( "hello world" ) );
* std::cout << var << std::endl;
* @endcode
*
* @param t variable to be converted in string
* @return A string
*/
template <class T>
inline std::string toString ( const T& t )
{
  std::stringstream ss;
  ss << t;
  return ss.str( );
}

#endif
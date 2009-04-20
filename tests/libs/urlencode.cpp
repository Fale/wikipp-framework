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

#include <iostream>
#include <string>

#include <libs/urlencode.h>

bool complete()
{
  if ( wikipp::libs::urlEncode::complete( "http://en.wikipedia.org/test" ) == "%68%74%74%70%3A%2F%2F%65%6E%2E%77%69%6B%69%70%65%64%69%61%2E%6F%72%67%2F%74%65%73%74" )
  {
    std::cout << "URLENCODE.Complete: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "URLENCODE.Complete: Error" << std::endl;
    return 1;
  }
}

bool minimal()
{
  if ( wikipp::libs::urlEncode::minimal( "http://en.wikipedia.org/test" ) == "http%3A%2F%2Fen%2Ewikipedia%2Eorg%2Ftest" )
  {
    std::cout << "URLENCODE.Minimal: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "URLENCODE.Minimal: Error" << std::endl;
    return 1;
  }
}

bool urlComplete()
{
  if ( wikipp::libs::urlEncode::urlencode( "http://en.wikipedia.org/test", 1 ) == "%68%74%74%70%3A%2F%2F%65%6E%2E%77%69%6B%69%70%65%64%69%61%2E%6F%72%67%2F%74%65%73%74" )
  {
    std::cout << "URLENCODE.NewComplete: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "URLENCODE.NewComplete: Error" << std::endl;
    return 1;
  }
}

bool urlMinimal()
{
  if ( wikipp::libs::urlEncode::urlencode( "http://en.wikipedia.org/test" ) == "http%3A%2F%2Fen%2Ewikipedia%2Eorg%2Ftest" )
  {
    std::cout << "URLENCODE.NewMinimal: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "URLENCODE.NewMinimal: Error" << std::endl;
    return 1;
  }
}

int main()
{
  int results;
  
  results = complete();
  results = results + minimal();
  results = results + urlComplete();
  results = results + urlMinimal();
  
  if ( results == 0 )
    std::cout << "Perfect" << std::endl;
  else
    std::cout << "Errors detected" << std::endl;
  return 0;
}

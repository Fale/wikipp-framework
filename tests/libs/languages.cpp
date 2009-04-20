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

#include <libs/languages.h>

bool translate()
{
  // Create the config file
  std::ofstream configFile;
  configFile.open ( "it.lang" );
  configFile << "home=casa;";
  configFile.close();

  // Bad hack
  wikipp::libs::i18n::translate( "home", "it" );

  std::string tr( wikipp::libs::i18n::translate( "home", "it" ) );

  if ( tr == "casa" )
  {
    std::cout << "TRANSLATE: OK (hack used)" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "TRANSLATE: Error" << tr << std::endl;
    return 1;
  }
}

int main()
{
  int results;

  results = translate();

  if ( results == 0 )
    std::cout << "Perfect" << std::endl;
  else
    std::cout << "Errors detected" << std::endl;
  return 0;
}
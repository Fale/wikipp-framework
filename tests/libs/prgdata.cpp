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
#include <fstream>

#include <libs/prgdata.h>

void createTestFile()
{
  std::ofstream configFile;
  configFile.open ( "config" );
  configFile << "username=user;\npassword=pass;\nproject=proj;\npage=page;\ntimezone=Europe/Rome;\nlanguage=en;\nvartest=varval;";
  configFile.close();
}

bool username()
{
  if ( wikipp::libs::prgdata::getUsername() == "user" )
  {
    std::cout << "PRGDATA.getUsername: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "PRGDATA.getUsername: Error" << std::endl;
    return 1;
  }
}

bool password()
{
  if ( wikipp::libs::prgdata::getPassword() == "pass" )
  {
    std::cout << "PRGDATA.getPassword: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "PRGDATA.getPassword: Error" << std::endl;
    return 1;
  }
}

bool project()
{
  if ( wikipp::libs::prgdata::getProject() == "proj" )
  {
    std::cout << "PRGDATA.getProject: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "PRGDATA.getProject: Error" << std::endl;
    return 1;
  }
}

bool page()
{
  if ( wikipp::libs::prgdata::getPage() == "page" )
  {
    std::cout << "PRGDATA.getPage: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "PRGDATA.getPage: Error" << std::endl;
    return 1;
  }
}

bool tzone()
{
  if ( wikipp::libs::prgdata::getTimeZone() == "Europe/Rome" )
  {
    std::cout << "PRGDATA.getTimeZone: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "PRGDATA.getTimeZone: Error" << std::endl;
    return 1;
  }
}

bool language()
{
  if ( wikipp::libs::prgdata::getLanguage() == "en" )
  {
    std::cout << "PRGDATA.getLanguage: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "PRGDATA.getLanguage: Error" << std::endl;
    return 1;
  }
}

bool variable()
{
  if ( wikipp::libs::prgdata::getVariable( "vartest" ) == "varval" )
  {
    std::cout << "PRGDATA.getVariable: OK" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "PRGDATA.getVariable: Error" << std::endl;
    return 1;
  }
}

int main()
{
  int results;

  createTestFile();

  results = username();
  results = results + password();
  results = results + project();
  results = results + page();
  results = results + tzone();
  results = results + language();
  results = results + variable();

  if ( results == 0 )
    std::cout << "Perfect" << std::endl;
  else
    std::cout << "Errors detected" << std::endl;
  return 0;
}

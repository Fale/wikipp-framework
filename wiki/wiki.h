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

#ifndef WIKIPP_WIKI_H
#define WIKIPP_WIKI_H

#include <iostream>
#include <string>
#include <vector>

#include "categories.h"
#include "edittoken.h"
#include "images.h"
#include "login.h"
#include "move.h"
#include "read.h"
#include "relatedpages.h"
#include "user.h"
#include "write.h"

namespace wikipp
{

  /**
  * Convinient class that allows users to write less lines of code
  *
  * @author Fabio Alessandro Locati
  */
  class wiki
  {
    public:
      // Constructor
      wiki( std::string, std::string, std::string, std::string );

      // Basic settings
      void setSite( std::string );
      void setProject( std::string );
      void setLanguage( std::string );
      void setUsername( std::string );
      void setPassword( std::string );
      std::string getSite();
      std::string getProject();
      std::string getLanguage();
      std::string getUsername();
      std::string getPassword();

      // Categories.h
      std::vector<std::string> categoryFetchMembers( std::string, std::string, int, int );
      int categoryCountMembers( std::string, std::string );

      // EditToken.h
      std::string getEditToken( std::string );

      bool login( std::string, std::string, std::string );
      std::string readPage( std::string, std::string );
      std::string readSource( std::string, std::string );
    private:

      void generateSite();

      std::string site;
      std::string proj;
      std::string lang;
      std::string user;
      std::string pass;
  };
}

#endif

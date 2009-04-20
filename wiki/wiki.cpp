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

#ifndef WIKIPP_WIKI_CPP
#define WIKIPP_WIKI_CPP

#include "wiki.h"

/// Constructor
wikipp::wiki::wiki( std::string project = "wikipedia", std::string language = "en", std::string username = "", std::string password = "")
{
  proj = project;
  lang = language;
  user = username;
  pass = password;
  generateSite();
}

/// Basic settings
void wikipp::wiki::setSite( std::string url )
{
  site = url;
}

void wikipp::wiki::setProject( std::string project )
{
  proj = project;
  generateSite();
}

void wikipp::wiki::setLanguage( std::string language )
{
  lang = language;
  generateSite();
}

void wikipp::wiki::setUsername( std::string username )
{
  user = username;
}

void wikipp::wiki::setPassword( std::string password )
{
  pass = password;
}

void wikipp::wiki::generateSite()
{
  site = "http://" + lang + "." + proj + ".org";
}

std::string wikipp::wiki::getSite()
{
  return site;
}

std::string wikipp::wiki::getProject()
{
  return proj;
}

std::string wikipp::wiki::getLanguage()
{
  return lang;
}

std::string wikipp::wiki::getUsername()
{
  return user;
}

std::string wikipp::wiki::getPassword()
{
  return pass;
}

/// Categories.h
int wikipp::wiki::categoryCountMembers( std::string category, std::string url = site )
{
  return wikipp::wiki::categories::countMembers( url, category );
}

std::vector<std::string> wikipp::wiki::categoryFetchMembers( std::string category, std::string url = site, int limit = 500, int ns = 100 )
{
  return std::vector<std::string> wikipp::wiki::categories::fetchMembers( url, category, limit, ns );
}

/// EditToken.h
std::string wikipp:wiki::getEditToken( std::string url = site )
{
  return returnEditToken( url );
}


bool wikipp::wiki::login( std::string url = site, std::string username = user, std::string password = pass )
{
  return login::wikiLogin( url, username, password );
}

std::string wikipp::wiki::readPage( std::string page, std::string url = site )
{
  return read::readPage( url, page );
}

std::string wikipp::wiki::readSource(std::string page,  std::string url = site )
{
  return read::readSource( url, page );
}

#endif
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

#ifndef WIKIPP_WIKI_IMAGES_CPP
#define WIKIPP_WIKI_IMAGES_CPP

#include "images.h"

namespace wikipp
{
  namespace wiki
  {
    std::string images::getImageUrl( std::string site, std::string image )
    {
      std::string data( http::http::get( site, "wiki/File:" + image ) );
      boost::regex img( "(.*)<a href=\"http://upload.wikimedia.org/(.*)?\"><img alt=\"File:(.*)" );
      boost::smatch matches;
      boost::regex_match(data, matches, img);
      return "http://upload.wikimedia.org/" + matches[2];
    }

    std::string images::getImageData( std::string site, std::string image )
    {
      return read::readSource( site, "File:" + image );
    }

    std::string images::download( std::string site, std::string image )
    {
      std::string url( getImageUrl( site, image ) );
      boost::regex img( "(.*)\n" );
      boost::smatch matches;
      boost::regex_match( url, matches, img );
      http::wget::procedure( "wget \"http://upload.wikimedia.org/" + matches[1] + "\" -o log -O " + image );
      return matches[2];
    }

    bool images::remove( std::string image )
    {
      image = "rm " + image;
      char *wg;
      wg = new char[ image.length( ) + 1 ];
      std::strcpy( wg, image.c_str( ) );
      if ( std::system ( wg ) )
        return 1;
      else
        return 0;
    }

    std::string images::sha( std::string site, std::string image )
    {
      std::string data ( http::http::get( site, "w/api.php?action=query&titles=Image:" + image + "&prop=imageinfo&format=xml&iiprop=sha1" ) );
      boost::regex rx( "(.*)sha1=\"(.*?)\"(.*)" );
      boost::smatch matches;
      boost::regex_match( data, matches, rx );
      return matches[2];
    }

    bool images::verifyPresence( std::string site, std::string image )
    {
      if ( getImageUrl( site, image ) == "" )
        return 0;
      else
        return 1;
    }

    bool images::verifyEquality( std::string fSite, std::string fImage, std::string sSite, std::string sImage )
    {
      if ( sha( fSite, fImage ) == sha( sSite, sImage ) )
        return 1;
      else
        return 0;
    }

    int images::otrs( std::string data )
    {
      boost::regex rx( "(.*)otrs=(\\d*)(.*)" );
      boost::smatch matches;
      boost::regex_match( data, matches, rx );
      if ( matches[2] != "" )
        return toInt( matches[2] );
      rx = "(.*)otrs=#(\\d*)(.*)";
      boost::regex_match( data, matches, rx );
      if ( matches[2] != "" )
        return toInt( matches[2] );
      else
        return 0;
    }

    int images::otrs( std::string site, std::string image )
    {
      return otrs( getImageData( site, image ) );
    }
  }
}
#endif

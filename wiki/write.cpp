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

#ifndef WIKIPP_WIKI_WRITE_CPP
#define WIKIPP_WIKI_WRITE_CPP

#include "write.h"

namespace wikipp
{
  namespace wiki
  {
    bool write::checkNoBotFlag( std::string url, std::string page )
    {
      std::string text( read::readSource( url, page ) );
      boost::regex pat( ".*%7B%7Bnobot%7D%7D.*" );
      boost::smatch matches;
      if ( !boost::regex_match( text, matches, pat ) )
        return 0;
      else
        return 1;
    }

    void write::safeWrite( std::string url, std::string page, std::string text, std::string summary, std::string checkpage, bool bot, bool minor, bool safe, bool botsafe, bool recreate, bool watch, bool logged )
    {
      if ( checkpage == "bot.same" )
        checkpage = page;

      if ( checkNoBotFlag( url, checkpage ) == false )
        write::writePage( url, page, text, summary, bot, minor, safe, botsafe, recreate, watch, logged );
    }

    void write::writePage( std::string url, std::string page, std::string text, std::string summary, bool bot, bool minor, bool safe, bool botsafe, bool recreate, bool watch, bool logged )
    {
      std::string uri( "w/index.php?title=" + page + "&action=edit" );
      std::string str( http::http::get( url, uri ) );

      boost::regex startTimeE( "(.*)value=\"(.*)\" name=\"wpStarttime\"(.*)" );
      boost::smatch startTimeR;
      boost::regex_match( str, startTimeR, startTimeE );
      boost::regex editTimeE( "(.*)value=\"(.*)\" name=\"wpEdittime\"(.*)" );
      boost::smatch editTimeR;
      boost::regex_match( str, editTimeR, editTimeE );

      uri = "w/index.php?title=" + page + "&action=submit";

      if ( bot == true )
        uri += "&bot=1";

      std::string postvalues( "wpTextbox1=\"" + libs::urlEncode::urlencode( text ) + "\"&wpSummary=" + libs::urlEncode::urlencode( summary ) + "&wpStarttime=" + startTimeR[2] + "&wpEdittime=" + editTimeR[2] );

      if ( recreate == true )
        postvalues += "&wpRecreate=1";
      else
        postvalues += "&wpRecreate=0";
      if ( safe == true )
        postvalues += "&assert=user";
      if ( botsafe == true )
        postvalues += "&assert=bot";
      if ( watch == true )
        postvalues += "&wpWatchthis=1";
      if ( minor == true )
        postvalues += "&wpMinoredit=1";
      if ( logged == true )
        postvalues += "&wpEditToken=" + edittoken::returnEditToken( url );
      else
        postvalues += "&wpEditToken=%2B%5C";

      http::http::post( url, uri, postvalues );
    }

    void write::appendPage( std::string url, std::string page, std::string text, std::string summary, std::string checkpage, bool bot, bool minor, bool safe, bool botsafe, bool recreate, bool watch, bool logged )
    {
      std::string completeText = read::readSource( url, page ) + text;

      if ( checkNoBotFlag( url, checkpage ) == false )
        write::writePage( url, page, completeText, summary, bot, minor, safe, botsafe, recreate, watch, logged );
    }
  }
}
#endif

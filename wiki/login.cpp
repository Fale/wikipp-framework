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

#ifndef WIKIPP_WIKI_LOGIN_CPP
#define WIKIPP_WIKI_LOGIN_CPP

#include "login.h"

namespace wikipp
{
  namespace wiki
  {
    bool login::wikiLogin( std::string url, std::string user, std::string pass )
    {
      login::wikiLoginHTTP( url, user, pass );
      return login::wikiLoginAPI(  url, user, pass );
    }

    bool login::wikiLoginAPI( std::string url, std::string user, std::string pass )
    {
      std::string str( http::http::postRaw( url, "w/api.php?action=login&format=xml", "lgname=" + user + "&lgpassword=" + pass, 0 ) );
      return login::createCookie( url, str );
    }

    void login::wikiLoginHTTP( std::string url, std::string user, std::string pass )
    {
      #ifdef HTTP_WGET
        http::wget::procedure( "wget \"" + url + "/w/index.php?title=Special:Userlogin&action=submitlogin&type=login\" --post-data=\"wpName=" + user + "&wpPassword=" + pass + "&wpRemember=1&wpLoginattempt=Log+in\" -o log -O temp" );
      #endif
    }

    bool login::createCookie( std::string url, std::string str )
    {
      boost::regex successE( "(.*)result=\"(.{7})\"(.*)" );
      boost::smatch successR;
      boost::regex_match( str, successR, successE );
      if ( successR[2] == "Success" )
      {
        std::string out;

        #ifdef HTTP_WGET

          int dati;
          dati = libs::dati::sinceEpoch() + 2678400;
          std::string data = toString( dati );

        #endif

        boost::regex urlGlobalE( "(.*?)\\.(.*)" );
        boost::smatch urlGlobalR;
        boost::regex_match( url, urlGlobalR, urlGlobalE );

        boost::regex cprefixE( "(.*)cookieprefix=\"(.*)\" sessionid(.*)" );
        boost::smatch cprefixR;
        boost::regex_match( str, cprefixR, cprefixE );

        boost::regex localUserNameE( "(.*)Set-Cookie: " + cprefixR[2] + "UserName=(.*?);(.*)" );
        boost::smatch localUserNameR;
        boost::regex_match( str, localUserNameR, localUserNameE );

        boost::regex localUserIDE( "(.*)" + cprefixR[2] + "UserID=(.*?);(.*)" );
        boost::smatch localUserIDR;
        boost::regex_match( str, localUserIDR, localUserIDE );

        boost::regex localSessionE( "(.*)" + cprefixR[2] + "_session=(.*?);(.*)" );
        boost::smatch localSessionR;
        boost::regex_match( str, localSessionR, localSessionE );

        boost::regex centralTokenE( "(.*)Set-Cookie: centralauth_Token=(.*?);(.*)" );
        boost::smatch centralTokenR;
        boost::regex_match( str, centralTokenR, centralTokenE );

        boost::regex centralsessionE( "(.*)Set-Cookie: centralauth_Session=(.*?);(.*)" );
        boost::smatch centralsessionR;
        boost::regex_match( str, centralsessionR, centralsessionE );

        #ifdef HTTP_WGET

          out = "# Sperimental cookie made by WikiPP libs (SUL actived)\n\n";
          out += url + "\tFALSE\t/\tFALSE\t" + data + "\t" + cprefixR[2] + "UserName\t" + localUserNameR[2] + "\n";
          out += url + "\tFALSE\t/\tFALSE\t" + data + "\t" + cprefixR[2] + "UserID\t" + localUserIDR[2] + "\n";
          out += url + "\tFALSE\t/\tFALSE\t" + data + "\t" + cprefixR[2] + "_session\t" + localSessionR[2] + "\n";
          out += "." + urlGlobalR[2] + "\tTRUE\t/\tFALSE\t" + data + "\tcentralauth_Token\t" + centralTokenR[2] + "\n";
          out += "." + urlGlobalR[2] + "\tTRUE\t/\tFALSE\t" + data + "\tcentralauth_User\t" + localUserNameR[2] + "\n";
          out += "." + urlGlobalR[2] + "\tTRUE\t/\tFALSE\t" + data + "\tcentralauth_session\t" + centralsessionR[2] + "\n";

        #else

          out = "Cookie: Username=" + localUserNameR[2] + "; ";
          out += "UserID=" + localUserIDR[2] + "; ";
          out += "_session=" + localSessionR[2] + "; ";
          out += "centralauth_Token=" + centralTokenR[2] + "; ";
          out += "centralauth_User=" + localUserNameR[2] + "; ";
          out += "centralauth_session=" + centralsessionR[2];

        #endif

        std::ofstream outfile ( "cookie",std::ofstream::binary );
        outfile.write( toChar( out ), out.length() );

        return 1;
      }
      else
      {
        std::cout << successR[2] << std::endl;
        return 0;
      }
    }

    bool login::logout()
    {
      if( std::system ( "rm cookie" ) )
        return 1;
      else
        return 0;
    }
  }
}
#endif

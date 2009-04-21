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

#ifndef WIKIPP_WIKI_WRITE_H
#define WIKIPP_WIKI_WRITE_H

#include <iostream>
#include <string>

#include <boost/regex.hpp>

#include "../http/http.h"
#include "../libs/urlencode.h"
#include "edittoken.h"
#include "read.h"

namespace wikipp
{
  namespace wiki
  {
    /**
     * Class that take care about the writing on a wiki
     *
     * @author Fabio Alessandro Locati
     *
     * @todo Create the write/API module
     */
    class write
    {
      public:
        /**
         * Function that is able to check if there is a bot block (with the presence of {{nobot}}).
         *
         * @code
         * std::cout << wikipp::wiki::write::checkNoBotFlag( "en.wikipedia.org", "wiki/User:Fale" ) << std::endl;
         * @endcode
         *
         * @param url Link to the project home (ie: "en.wikipedia.org")
         * @param page Page to be checked by the function (default: Main_Page)
         * @return 1 if the string {{nobot}} is present, 0 if there isn't
         */
        static bool checkNoBotFlag( std::string, std::string page = "Main_Page" );

        /**
         * Function that is able to write a content on a wiki project after have checked if the bot block is <b>not></b> present
         *
         * @code
         * wikipp::wiki::write::safeWrite( "en.wikipedia.org", "User:Fale", "Hello, I'm a text" );
         * @endcode
         *
         * @param url Link to the project home (ie: "en.wikipedia.org")
         * @param page Page to be checked by the function
         * @param text Text to be printed in the page
         * @param summary Summary to be assigned to the edit (default: CPP.Bot.Edit)
         * @param checkpage Page to be checked for the presence of the {{nobot}} tag (default: The same page as the edit)
         * @param bot insert the bot flag (default: true)
         * @param minor insert the minor flag (default: false)
         * @param safe force the control (it does nothing, but is mandatory if you want to use the next options)(default: false)
         * @param botsafe force to be flagged as bot to be able to edit the page (default: false)
         * @param recreate recreate the page if the page no longher exists (default: false)
         * @param watch insert the page in the watch list (default: false)
         * @param logged Determs if the edit token has to be sent or has to be sent an empty edittoken (default: true)
         */
        static void safeWrite( std::string, std::string, std::string, std::string summary = "Wiki++.Bot", std::string checkpage = "bot.same", bool bot = true, bool minor = false, bool safe = false, bool botsafe = false, bool recreate = false, bool watch = false, bool logged = true );

        /**
         * Function that is able to write without any controls before
         *
         * @code
         * wikipp::wiki::write::writePage( "en.wikipedia.org", "User:Fale", "Hello, I'm a text" );
         * @endcode
         *
         * @param url Link to the project home (ie: "en.wikipedia.org")
         * @param page Page to be checked by the function
         * @param text Text to be printed in the page
         * @param summary Summary to be assigned to the edit (default: CPP.Bot.Edit)
         * @param bot insert the bot flag (default: true)
         * @param minor insert the minor flag (default: false)
         * @param safe force the control (it does nothing, but is mandatory if you want to use the next options)(default: false)
         * @param botsafe force to be flagged as bot to be able to edit the page (default: false)
         * @param recreate recreate the page if the page no longher exists (default: false)
         * @param watch insert the page in the watch list (default: false)
         * @param logged Determs if the edit token has to be sent or has to be sent an empty edittoken (default: true)
         */
        static void writePage( std::string, std::string, std::string, std::string summary = "Wiki++.Bot", bool bot = true, bool minor = false, bool safe = false, bool botsafe = false, bool recreate = false, bool watch = false, bool logged = true );

        /**
        * Function that is able to append some text in the end of the page without any controls before
        *
        * @code
        * wikipp::wiki::write::appendPage( "en.wikipedia.org", "User:Fale", "Hello, I'm a text" );
        * @endcode
        *
        * @param url Link to the project home (ie: "en.wikipedia.org")
        * @param page Page to be checked by the function
        * @param text Text to be printed in the page
        * @param summary Summary to be assigned to the edit (default: CPP.Bot.Edit)
        * @param bot insert the bot flag (default: true)
        * @param minor insert the minor flag (default: false)
        * @param safe force the control (it does nothing, but is mandatory if you want to use the next options)(default: false)
        * @param botsafe force to be flagged as bot to be able to edit the page (default: false)
        * @param recreate recreate the page if the page no longher exists (default: false)
        * @param watch insert the page in the watch list (default: false)
        * @param logged Determs if the edit token has to be sent or has to be sent an empty edittoken (default: true)
        */
        static void appendPage( std::string, std::string, std::string, std::string summary = "Wiki++.Bot", std::string checkpage = "bot.same", bool bot = true, bool minor = false, bool safe = false, bool botsafe = false, bool recreate = false, bool watch = false, bool logged = true );
    };
  }
}
#endif

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

#ifndef WIKIPP_EXTENDED_MOVE
#define WIKIPP_EXTENDED_MOVE

#include <libs/dati.h>
#include <libs/languages.h>
#include <wiki/write.h>
#include <wiki/move.h>
#include <wiki/relatedpages.h>

namespace wikipp
{
  namespace extended
  {
    class storm
    {
      private:
        std::string language;
        std::string timezone;
        std::string frequence;

      public:

        storm()
        {
          language = "en-en";
          timezone = "Europe/London";
          frequence = "weekly";
        }

        // General move Page function & prints the message in the talk page
        void movePage( std::string proj, std::string page, std::string freq = frequence )
        {
          std::string spName( libs::dati::date( timezone, i18n( "Sub page name format" ) ) );
          std::string pageto( page + "/" + i18n( "Archive" ) + "/" + spName );
          std::string text( i18n( "MoveBot has moved the data since" ) + previousStorm() + i18n( "and to today to [this link|" ) + pageto + "].\n\n~~~~" );
          std::string summary( i18n( "MoveBot: Archiving old data" ) );

          wiki::move::movePage( proj, page, pageto, summary );
          wiki::write::appendPage( proj, wiki::relatedPages::toTalk( page ), text, summary);
        }

        // Function that is in charge of returning the previous storm date
        std::string previousStorm()
        {
          std::string datiFormat( i18n( "Date format" ) );
          std::string since( i18n( "Since" ) );
          /*switch frequence{//TODO: Check the switch syntax and implement the past/future date and the custom format in wikipp::libs::dati::*
            case "initial" : return i18n( "Since the begin" );
            case "hourly" : return since + libs::dati::date( timezone, datiFormat, "-1h" );
            case "daily" : return since + libs::dati::date( timezone, datiFormat, "-1d" );
            case "weekly" : return since + libs::dati::date( timezone, datiFormat, "-7d" );
            case "monthly" : return since + libs::dati::date( timezone, datiFormat, "-1m" );
            case "yearly" : return since + libs::dati::date( timezone, datiFormat, "-1y" );
          };*/
        }

        // Shortcut for wikipp::libs::language::i18n
        std::string i18n( std::string str )
        {
          return libs::languages::i18n( str, language );
        }

        void setLang( std::string lang )
        {
          language = lang;
        }

        void setTZ( std::string tz )
        {
          timezone = tz;
        }

        void setFreq( std::string freq )
        {
          frequence = freq;
        }
    };
  }
}

#endif

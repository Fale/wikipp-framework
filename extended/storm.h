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

#ifndef WIKIPP_EXTENDED_STORM_H
#define WIKIPP_EXTENDED_STORM_H

#include "../libs/convert.h"
#include "../libs/dati.h"
#include "../libs/languages.h"
#include "../wiki/write.h"
#include "../wiki/move.h"
#include "../wiki/relatedpages.h"

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
        storm();

        // General move Page function & prints the message in the talk page
        void movePage( std::string, std::string, std::string freq = "def" );

        // Function that is in charge of returning the previous storm date
        std::string previousStorm();

        // Shortcut for wikipp::libs::language::i18n
        std::string i18n( std::string );

        void setLang( std::string );

        void setTZ( std::string );

        void setFreq( std::string );
    };
  }
}

#endif

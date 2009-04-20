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

#ifndef WIKIPP_EXTENDED_CURRENCY_CPP
#define WIKIPP_EXTENDED_CURRENCY_CPP

#include"currency.h"

namespace wikipp
{
  namespace extended
  {
    std::string currency::yahoo( std::string currencyfrom, std::string currencyto )
    {
      std::vector<std::string> dataNew = fetchNewData( currencyfrom, currencyto );
      std::vector<std::string> dataOld = fetchOldData( currencyfrom, currencyto );
      std::string img( compare( dataOld, dataNew ) );
      return dataNew[0] + img;
    }

    std::string currency::yahooBotB( std::string currencyfrom, std::string currencyto )
    {
      std::vector<std::string> dataNew = fetchNewData( currencyfrom, currencyto );
      std::vector<std::string> dataOld = fetchOldData( currencyfrom, currencyto, 0 );
      std::vector<std::string> dataNewR = fetchNewData( currencyto, currencyfrom );
      std::vector<std::string> dataOldR = fetchOldData( currencyto, currencyfrom, 1 );
      std::string img = compare( dataOld, dataNew );
      std::string imgR = compare( dataOldR, dataNewR );
      std::vector<std::string> images = errorManagerBotB( img, imgR );
      return "|" + dataNew[0] + " " + images[0] + "\n|" + dataNewR[0] + " " + images[1] + "\n";
    }

    void currency::savefile( std::string currencyfrom )
    {
      bkpfile = stream.str();
      char *wg;
      wg = new char[bkpfile.length() + 1];
      std::strcpy( wg, bkpfile.c_str() );
      std::string filename;
      #ifdef CURRENCYBOT_A
      filename = "previous";
      #endif
      #ifdef CURRENCYBOT_B
      filename = "previous" + currencyfrom;
      #endif
      char *fn;
      fn = new char[filename.length() + 1];
      std::strcpy( fn, filename.c_str() );
      std::ofstream outfile ( fn, std::ofstream::binary );
      outfile.write ( wg, bkpfile.length() );
    }

    std::vector<std::string> currency::fetchNewData( std::string currencyfrom, std::string currencyto )
    {
      std::vector<std::string> ret;

      std::string data( wikipp::http::http::get( "it.finance.yahoo.com","valuta/convert?amt=1&from=" + currencyfrom + "&to=" + currencyto + "&submit=Converti" ) );
      boost::regex pat( "(.*)<b>1</b></td><td class=\"yfnc_tabledata1\">(.*)?</td><td class=\"yfnc_tabledata1\">(.*)?</td><td class=\"yfnc_tabledata1\"><b>(.*)?</b></td>(.*)" );
      boost::smatch matches;
      boost::regex_match( data, matches, pat );
      ret.push_back( matches[3] );
      boost::regex tat( "(.*)<b>1</b></td><td class=\"yfnc_tabledata1\">(.*)?</td><td class=\"yfnc_tabledata1\">(.*)?</td><td class=\"yfnc_tabledata1\"><b>(\\d+)?\\.?(\\d{1,3})\\,?(\\d+)?</b></td>(.*)" );
      boost::regex_match( data, matches, tat );

      ret.push_back( matches[4] );
      ret.push_back( matches[5] );
      ret.push_back( matches[6] );

      #ifdef PREVIOUS
      stream << "from " << currencyfrom << " to " << currencyto << ": " << ret[0] << std::endl;
      #endif
      #define DEBUG_PRG
      #ifdef DEBUG_PRG
      std::cout << "from " << currencyfrom << " to " << currencyto << ": " << ret[0] << std::endl;
      #endif
      return ret;
    }

    std::vector<std::string> currency::fetchOldData( std::string currencyfrom, std::string currencyto, bool inverted )
    {
      char *fn;
      std::stringstream sstr;
      std::string fileData;
      std::string filename;
      std::vector<std::string> ret;
      #ifdef CURRENCYBOT_A
      filename = "previous";
      #endif
      #ifdef CURRENCYBOT_B
      if ( inverted == 1 )
        filename = "previous" + currencyto;
      else
        filename = "previous" + currencyfrom;
      #endif
      fn = new char[filename.length() + 1];
      std::strcpy( fn, filename.c_str() );
      std::ifstream file( fn );
      sstr << file.rdbuf();
      fileData = sstr.str();
      boost::regex pat( "(.*)from " + currencyfrom + " to " + currencyto + ": (.+)?\nfrom(.*)" );
      boost::smatch prev;
      boost::regex_match( fileData, prev, pat );
      ret.push_back( prev[2] );
      boost::regex tat( "(.*)from " + currencyfrom + " to " + currencyto + ": (\\d+)?\\.?(\\d{1,3})\\,(\\d+)?\nfrom(.*)" );
      boost::regex_match( fileData, prev, tat );
      ret.push_back( prev[2] );
      ret.push_back( prev[3] );
      ret.push_back( prev[4] );
      return ret;
    }

    std::string currency::compare( std::vector<std::string> oldData, std::vector<std::string> newData )
    {
      std::string img;
      if ( oldData[1] > newData[1] )
        img = "[[Immagine:Red_Arrow_Down.svg|10px]]";// DOWN
      if ( oldData[1] < newData[1] )
        img = "[[Immagine:Green_Arrow_Up.svg|10px]]";// UP
      if ( oldData[1] == newData[1] )
      {
        if ( oldData[2] > newData[2] )
          img = "[[Immagine:Red_Arrow_Down.svg|10px]]";// DOWN
        if ( oldData[2] <  newData[2] )
          img = "[[Immagine:Green_Arrow_Up.svg|10px]]";// UP
        if ( oldData[2] == newData[2] )
        {
          if ( oldData[3] > newData[3] )
            img = "[[Immagine:Red_Arrow_Down.svg|10px]]";// DOWN
          if ( oldData[3] < newData[3] )
            img = "[[Immagine:Green_Arrow_Up.svg|10px]]";// UP
          if ( oldData[3] == newData[3] )
            img = "[[Immagine:Equal.svg|10px]]";// EQUAL
        }
      }
      return img;
    }

    std::vector<std::string> currency::errorManagerBotB( std::string imgOne, std::string imgTwo )
    {
      std::vector<std::string> img;
      // IF THE FIRST IS DOWN
      if ( imgOne == "[[Immagine:Red_Arrow_Down.svg|10px]]" && imgTwo == "[[Immagine:Red_Arrow_Down.svg|10px]]" )
      {
        img.push_back( "[[Immagine:Red_Arrow_Down.svg|10px]]" ); // DOWN THE FIRST
        img.push_back( "[[Immagine:Green_Arrow_Up.svg|10px]]" ); // UP THE SECOND
      }
      if ( imgOne == "[[Immagine:Red_Arrow_Down.svg|10px]]" && imgTwo == "[[Immagine:Equal.svg|10px]]" )
      {
        img.push_back( "[[Immagine:Red_Arrow_Down.svg|10px]]" ); // DOWN THE FIRST
        img.push_back( "[[Immagine:Green_Arrow_Up.svg|10px]]" ); // UP THE SECOND
      }
      if ( imgOne == "[[Immagine:Red_Arrow_Down.svg|10px]]" && imgTwo == "[[Immagine:Green_Arrow_Up.svg|10px]]" )
      {
        img.push_back( "[[Immagine:Red_Arrow_Down.svg|10px]]" ); // DOWN THE FIRST
        img.push_back( "[[Immagine:Green_Arrow_Up.svg|10px]]" ); // UP THE SECOND
      }
      // IF THE FIRST IS EQUAL
      if ( imgOne == "[[Immagine:Equal.svg|10px]]" && imgTwo == "[[Immagine:Red_Arrow_Down.svg|10px]]" )
      {
        img.push_back( "[[Immagine:Green_Arrow_Up.svg|10px]]" ); // UP THE FIRST
        img.push_back( "[[Immagine:Red_Arrow_Down.svg|10px]]" ); // DOWN THE SECOND
      }
      if ( imgOne == "[[Immagine:Equal.svg|10px]]" && imgTwo == "[[Immagine:Equal.svg|10px]]" )
      {
        img.push_back( "[[Immagine:Equal.svg|10px]]" ); // EQUAL THE FIRST
        img.push_back( "[[Immagine:Equal.svg|10px]]" ); // EQUAL THE SECOND
      }
      if ( imgOne == "[[Immagine:Equal.svg|10px]]" && imgTwo == "[[Immagine:Green_Arrow_Up.svg|10px]]" )
      {
        img.push_back( "[[Immagine:Red_Arrow_Down.svg|10px]]" ); // DOWN THE FIRST
        img.push_back( "[[Immagine:Green_Arrow_Up.svg|10px]]" ); // UP THE SECOND
      }
      // IF THE FIRST IS UP
      if ( imgOne == "[[Immagine:Green_Arrow_Up.svg|10px]]" && imgTwo == "[[Immagine:Red_Arrow_Down.svg|10px]]" )
      {
        img.push_back( "[[Immagine:Green_Arrow_Up.svg|10px]]" ); // UP THE FIRST
        img.push_back( "[[Immagine:Red_Arrow_Down.svg|10px]]" ); // DOWN THE SECOND
      }
      if ( imgOne == "[[Immagine:Green_Arrow_Up.svg|10px]]" && imgTwo == "[[Immagine:Equal.svg|10px]]" )
      {
        img.push_back( "[[Immagine:Green_Arrow_Up.svg|10px]]" ); // UP THE FIRST
        img.push_back( "[[Immagine:Red_Arrow_Down.svg|10px]]" ); // DOWN THE SECOND
      }
      if ( imgOne == "[[Immagine:Green_Arrow_Up.svg|10px]]" && imgTwo == "[[Immagine:Green_Arrow_Up.svg|10px]]" )
      {
        img.push_back( "[[Immagine:Green_Arrow_Up.svg|10px]]" ); // UP THE SECOND
        img.push_back( "[[Immagine:Red_Arrow_Down.svg|10px]]" ); // DOWN THE FIRST
      }
      return img;
    }
  }
}
#endif

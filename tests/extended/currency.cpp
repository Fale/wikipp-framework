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

#include <libs/dati.h>
#include <extended/currency.h>

int main()
{
  std::string page ( "ciccio" );
  std::stringstream sstr;
  wikipp::extended::currency get;
  sstr << "{| border='1' cellpadding='3' cellspacing='0' style='text-align:center; margin-top:.5em; margin-bottom:.5em; border:1px solid #bbb; border-collapse:collapse;'" << std::endl;
  sstr << "|-bgcolor=#dddddd" << std::endl;
  sstr << "!width=16%|Cambio" << std::endl;
  sstr << "!width=12%|[[" + page + "/USD|Dollaro USA]] ($)" << std::endl;
  sstr << "!width=12%|[[" + page + "/EUR|Euro]] (€)" << std::endl;
  sstr << "!width=12%|[[" + page + "/JPY|Yen]] (¥)" << std::endl;
  sstr << "!width=12%|[[" + page + "/CAD|Dollaro Canadese]] ($)" << std::endl;
  sstr << "!width=12%|[[" + page + "/GBP|Sterlina]] (£)" << std::endl;
  sstr << "!width=12%|[[" + page + "/AUD|Dollaro Australiano]] ($)" << std::endl;
  sstr << "!width=12%|[[" + page + "/CHF|Franco Svizzero]] (Fr.)" << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/USD|Dollaro USA]] ($)" << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("USD","EUR") << std::endl;
  sstr << "|" + get.yahoo("USD","JPY") << std::endl;
  sstr << "|" + get.yahoo("USD","CAD") << std::endl;
  sstr << "|" + get.yahoo("USD","GBP") << std::endl;
  sstr << "|" + get.yahoo("USD","AUD") << std::endl;
  sstr << "|" + get.yahoo("USD","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/EUR|Euro]] (€)" << std::endl;
  sstr << "|" + get.yahoo("EUR","USD") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("EUR","JPY") << std::endl;
  sstr << "|" + get.yahoo("EUR","CAD") << std::endl;
  sstr << "|" + get.yahoo("EUR","GBP") << std::endl;
  sstr << "|" + get.yahoo("EUR","AUD") << std::endl;
  sstr << "|" + get.yahoo("EUR","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/JPY|Yen]] (¥)" << std::endl;
  sstr << "|" + get.yahoo("JPY","USD") << std::endl;
  sstr << "|" + get.yahoo("JPY","EUR") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("JPY","CAD") << std::endl;
  sstr << "|" + get.yahoo("JPY","GBP") << std::endl;
  sstr << "|" + get.yahoo("JPY","AUD") << std::endl;
  sstr << "|" + get.yahoo("JPY","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/CAD|Dollaro Canadese]] ($)" << std::endl;
  sstr << "|" + get.yahoo("CAD","USD") << std::endl;
  sstr << "|" + get.yahoo("CAD","EUR") << std::endl;
  sstr << "|" + get.yahoo("CAD","JPY") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("CAD","GBP") << std::endl;
  sstr << "|" + get.yahoo("CAD","AUD") << std::endl;
  sstr << "|" + get.yahoo("CAD","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/GBP|Sterlina]] (£)" << std::endl;
  sstr << "|" + get.yahoo("GBP","USD") << std::endl;
  sstr << "|" + get.yahoo("GBP","EUR") << std::endl;
  sstr << "|" + get.yahoo("GBP","JPY") << std::endl;
  sstr << "|" + get.yahoo("GBP","CAD") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("GBP","AUD") << std::endl;
  sstr << "|" + get.yahoo("GBP","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/AUD|Dollaro Australiano]] ($)" << std::endl;
  sstr << "|" + get.yahoo("AUD","USD") << std::endl;
  sstr << "|" + get.yahoo("AUD","EUR") << std::endl;
  sstr << "|" + get.yahoo("AUD","JPY") << std::endl;
  sstr << "|" + get.yahoo("AUD","CAD") << std::endl;
  sstr << "|" + get.yahoo("AUD","GBP") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("AUD","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/CHF|Franco Svizzero]] (Fr.)" << std::endl;
  sstr << "|" + get.yahoo("CHF","USD") << std::endl;
  sstr << "|" + get.yahoo("CHF","EUR") << std::endl;
  sstr << "|" + get.yahoo("CHF","JPY") << std::endl;
  sstr << "|" + get.yahoo("CHF","CAD") << std::endl;
  sstr << "|" + get.yahoo("CHF","GBP") << std::endl;
  sstr << "|" + get.yahoo("CHF","AUD") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|}" << std::endl;
  std::vector<int> time = wikipp::libs::dati::dateTime();
  sstr << "Aggiornato alle " << time[2] << ":" << time[1] << ":" << time[0];
  sstr << " del " << time[3] << "/" << time[4] << "/" << time[5] << "." << std::endl << std::endl;
  sstr << "I dati potrebbero essere ritardati di 15 o 20 minuti.";
  std::string text( sstr.str() );
  std::cout << text;
}
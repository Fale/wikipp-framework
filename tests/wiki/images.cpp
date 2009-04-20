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

#include <wiki/images.h>

int main()
{
  std::cout << wikipp::wiki::images::getImageUrl( "commons.wikimedia.org", "Symbol_kept_vote.svg" ) << std::endl;
  std::cout << wikipp::wiki::images::getImageData( "commons.wikimedia.org", "Symbol_kept_vote.svg" ) << std::endl;
  std::cout << wikipp::wiki::images::sha( "commons.wikimedia.org", "Symbol_kept_vote.svg" ) << std::endl;
  return 0;
}
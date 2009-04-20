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

#ifndef WIKIPP_HTTP_CPP
#define WIKIPP_HTTP_CPP

#include "http.h"

namespace wikipp
{
  namespace http
  {
    http::http( std::string bkd, std::string ua)
    {
      backend = bkd;
      useragent = ua;
    }

    void http::setBackend( std::string bkd )
    {
      backend = bkd;
    }

    void http::setUserAgent( std::string ua )
    {
      useragent = ua;
    }

    std::string http::getBackend()
    {
      return backend;
    }

    std::string http::getUserAgent()
    {
      return useragent;
    }

    std::string http::igetRaw( std::string url, std::string link, bool cookies, std::string ua )
    {
      if ( backend == "asio" )
        return asio::getRaw( url, link, cookies, ua );
      if ( backend == "wget" )
        return wget::get( url, link, cookies, ua );
    }

    std::string http::iget( std::string url, std::string link, bool cookies, std::string ua )
    {
      if ( backend == "asio" )
        return asio::getRaw( url, link, cookies, ua );
      if ( backend == "wget" )
        return wget::get( url, link, cookies, ua );
    }

    std::string http::ipostRaw( std::string url, std::string link, std::string postValues, bool cookies, std::string ua )
    {
      if ( backend == "asio" )
        return asio::post( url, link, postValues, cookies, ua );
      if ( backend == "wget" )
        return wget::post( url, link, postValues, cookies, ua );
    }

    std::string http::ipost( std::string url, std::string link, std::string postValues, bool cookies, std::string ua )
    {
      if ( backend == "asio" )
        return asio::post( url, link, postValues, cookies, ua );
      if ( backend == "wget" )
        return wget::post( url, link, postValues, cookies, ua );
    }

    std::string http::getRaw( std::string url, std::string link, bool cookies, std::string bkd, std::string ua )
    {
      if ( bkd == "asio" )
        return asio::getRaw( url, link, cookies, ua );
      if ( bkd == "wget" )
        return wget::get( url, link, cookies, ua );
    }

    std::string http::get( std::string url, std::string link, bool cookies, std::string bkd, std::string ua )
    {
      if ( bkd == "asio" )
        return asio::getRaw( url, link, cookies, ua );
      if ( bkd == "wget" )
        return wget::get( url, link, cookies, ua );
    }

    std::string http::postRaw( std::string url, std::string link, std::string postValues, bool cookies, std::string bkd, std::string ua )
    {
      if ( bkd == "asio" )
        return asio::post( url, link, postValues, cookies, ua );
      if ( bkd == "wget" )
        return wget::post( url, link, postValues, cookies, ua );
    }

    std::string http::post( std::string url, std::string link, std::string postValues, bool cookies, std::string bkd, std::string ua )
    {
      if ( bkd == "asio" )
        return asio::post( url, link, postValues, cookies, ua );
      if ( bkd == "wget" )
        return wget::post( url, link, postValues, cookies, ua );
    }

  }
}

#endif

/*
    Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008 Christopher M. Kohlhoff - chris@kohlhoff.com
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

#ifndef WIKIPP_HTTP_ASIO_CPP
#define WIKIPP_HTTP_ASIO_CPP

#include "asio.h"

using boost::asio::ip::tcp;

namespace wikipp
{
  namespace http
  {
    std::string asio::getRaw( std::string const& url, std::string const& link, bool loadCookies, std::string const& ua )
    {
      using namespace boost::asio::ip;

      boost::asio::io_service ioService;

      // Get a list of endpoints corresponding to the server name.
      tcp::resolver resolver( ioService );
      tcp::resolver::query query( url, "http" );
      tcp::resolver::iterator endpointIterator = resolver.resolve( query );
      tcp::resolver::iterator end;

      // Try each endpoint until we successfully establish a connection.
      tcp::socket socket( ioService );
      boost::system::error_code error = boost::asio::error::host_not_found;
      while ( error && endpointIterator != end )
      {
        socket.close();
        socket.connect( *endpointIterator++, error );
      }
      if ( error )
        throw boost::system::system_error( error );

      // Form the request. We specify the "Connection: close" header so that the
      // server will close the socket after transmitting the response. This will
      // allow us to treat all data up until the EOF as the content.
      boost::asio::streambuf request;
      std::ostream requestStream( &request );
      requestStream << "GET /" << link << " HTTP/1.1\r\n";
      requestStream << "Host: " << url << "\r\n";
      if ( loadCookies )
      {
        std::ifstream file( "cookie" );
        std::string cookie;
        std::string line;
        while (! file.eof() )
        {
          getline ( file, line );
          cookie += line;
        }
        if ( cookie != "" )
          requestStream << cookie;
      }
      requestStream << "User-Agent:" << ua << "\r\n";
      requestStream << "Accept: */*\r\n";
      requestStream << "Connection: close\r\n\r\n";

      // Send the request.
      boost::asio::write( socket, request );

      // Read the response status line.
      boost::asio::streambuf response;
      boost::asio::read_until( socket, response, "\r\n" );

      // Check that response is OK.
      std::istream responseStream( &response );
      std::string httpVersion;
      responseStream >> httpVersion;
      unsigned int statusCode;
      responseStream >> statusCode;
      std::string statusMessage;
      std::getline( responseStream, statusMessage );
      if ( !responseStream || httpVersion.substr(0, 5) != "HTTP/" )
      {
        std::cout << "Invalid response\n";
        return std::string();
      }
      if ( statusCode != 200 )
      {
        std::cout << "Response returned with status code " << statusCode << "\n";
        return std::string();
      }

      // Read the response headers, which are terminated by a blank line.
      boost::asio::read_until( socket, response, "\r\n\r\n" );

      // Process the response headers.
      std::stringstream sstr;
      std::string header;
      while ( std::getline( responseStream, header ) && header != "\r" )
        sstr << header << "\n";
      sstr << "\n";

      // Write whatever content we already have to output.
      if ( response.size() > 0 )
        sstr << &response;

      // Read until EOF, writing data to output as we go.
      while ( boost::asio::read( socket, response, boost::asio::transfer_at_least( 1 ), error ) )
        sstr << &response;
      if ( error != boost::asio::error::eof )
        throw boost::system::system_error( error );

      return sstr.str();
    }


    std::string asio::get( std::string const& url, std::string const& link, bool loadCookies, std::string const& ua )
    {
      std::string text( getRaw( url, link, loadCookies, ua ) );
      boost::regex expression( "(.*)\n\n(.*)" );
      boost::smatch matches;
      boost::regex_match(text, matches, expression);
      return matches[2];
    }

    std::string asio::postRaw( std::string const& url, std::string const& link, std::string postData, bool loadCookies, std::string const& ua )
    {
      using namespace boost::asio::ip;

      boost::asio::io_service ioService;

      // Get a list of endpoints corresponding to the server name.
      tcp::resolver resolver( ioService );
      tcp::resolver::query query( url, "http" );
      tcp::resolver::iterator endpointIterator = resolver.resolve( query );
      tcp::resolver::iterator end;

      // Try each endpoint until we successfully establish a connection.
      tcp::socket socket( ioService );
      boost::system::error_code error = boost::asio::error::host_not_found;
      while ( error && endpointIterator != end )
      {
        socket.close();
        socket.connect( *endpointIterator++, error );
      }
      if ( error )
          throw boost::system::system_error( error );

      // Form the request. We specify the "Connection: close" header so that the
      // server will close the socket after transmitting the response. This will
      // allow us to treat all data up until the EOF as the content.
      boost::asio::streambuf request;
      std::ostream requestStream( &request );
      requestStream << "POST /" << link << " HTTP/1.1\r\n";
      requestStream << "Host: " << url << "\r\n";
      if ( loadCookies )
      {
        std::ifstream file( "cookie" );
        std::string cookie;
        std::string line;
        while (! file.eof() )
        {
          getline ( file, line );
          cookie += line;
        }
        if ( cookie != "" )
          requestStream << cookie;
      }
      requestStream << "User-Agent:" << ua << "\r\n";
      requestStream << "Accept: */*\r\n";
      requestStream << "Content-Type: application/x-www-form-urlencoded\r\n";
      requestStream << "Content-Length: " << postData.length() << "\r\n";
      requestStream << "Connection: close\r\n\r\n";
      requestStream << postData;

      // Send the request.
      boost::asio::write( socket, request );

      // Read the response status line.
      boost::asio::streambuf response;
      boost::asio::read_until( socket, response, "\r\n" );

      // Check that response is OK.
      std::istream responseStream( &response );
      std::string httpVersion;
      responseStream >> httpVersion;
      unsigned int statusCode;
      responseStream >> statusCode;
      std::string statusMessage;
      std::getline( responseStream, statusMessage );
      if ( !responseStream || httpVersion.substr(0, 5) != "HTTP/" )
      {
        std::cout << "Invalid response\n";
        return std::string();
      }
      if ( statusCode != 200 )
      {
        std::cout << "Response returned with status code " << statusCode << "\n";
        return std::string();
      }

      // Read the response headers, which are terminated by a blank line.
      boost::asio::read_until( socket, response, "\r\n\r\n" );

      // Process the response headers.
      std::stringstream sstr;
      std::string header;
      while ( std::getline( responseStream, header ) && header != "\r" )
        sstr << header << "\n";
      sstr << "\n";

      // Write whatever content we already have to output.
      if ( response.size() > 0 )
        sstr << &response;

      // Read until EOF, writing data to output as we go.
      while ( boost::asio::read(socket, response, boost::asio::transfer_at_least( 1 ), error ) )
        sstr << &response;
      if ( error != boost::asio::error::eof )
        throw boost::system::system_error( error );

      return sstr.str();
    }

    std::string asio::post( std::string const& url, std::string const& link, std::string postData, bool loadCookies, std::string const& ua )
    {
      std::string text( asio::postRaw( url, link, postData, loadCookies, ua ) );
      boost::regex expression( "(.*)\n\n(.*)" );
      boost::smatch matches;
      boost::regex_match(text, matches, expression);
      return matches[2];
    }
  }
}
#endif

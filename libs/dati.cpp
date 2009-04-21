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

#ifndef WIKIPP_LIBS_DATI_CPP
#define WIKIPP_LIBS_DATI_CPP

#include "dati.h"

namespace wikipp
{
  namespace libs
  {
    int dati::sinceEpoch()
    {
      boost::posix_time::ptime time_t_epoch( boost::gregorian::date( 1970,1,1 ) );
      boost::posix_time::ptime t( boost::posix_time::second_clock::local_time() );
      boost::posix_time::time_duration diff = t - time_t_epoch;
      return diff.total_seconds();
    }

    std::vector<int> dati::dateTime()
    {
      std::vector<int> ret;
      boost::posix_time::ptime t( boost::posix_time::second_clock::local_time() );

      tm ldttm = boost::posix_time::to_tm( t );
      ret.push_back( ldttm.tm_sec );
      ret.push_back( ldttm.tm_min );
      ret.push_back( ldttm.tm_hour );
      ret.push_back( ldttm.tm_mday );
      ret.push_back( ldttm.tm_mon + 1 );
      ret.push_back( ldttm.tm_year + 1900 );

      return ret;
    }
/*
    int dati::sinceEpoch( std::string tz = "Europe/London" )
    {
      tz_database tz_db;
      tz_db.load_from_file( "/home/fale/date_time_zones.csv" );
      time_zone_ptr zone = tz_db.time_zone_from_region( tz );
      local_date_time ldt = local_microsec_clock::local_time( zone );
      ptime time_t_epoch( date( 1970,1,1 ) );
      time_duration diff = ldt.utc_time() - time_t_epoch;

      return diff.total_seconds();
    }

    std::vector<int> dati::dateTime( std::string tz = "Europe/London" )
    {
      std::vector<int> ret;
      tz_database tz_db;
      tz_db.load_from_file( "/home/fale/date_time_zones.csv" );
      time_zone_ptr zone = tz_db.time_zone_from_region( tz );
      local_date_time ldt = local_microsec_clock::local_time( zone );

      tm ldttm = to_tm( ldt );
      ret.push_back( ldttm.tm_sec );
      ret.push_back( ldttm.tm_min );
      ret.push_back( ldttm.tm_hour );
      ret.push_back( ldttm.tm_mday );
      ret.push_back( ldttm.tm_mon + 1 );
      ret.push_back( ldttm.tm_year + 1900 );

      return ret;
    }

    std::string dati::standardDate( std::string tz = "Europe/London" )
    {
      std::vector<int> time = wikipp::libs::dati::dateTime( tz );
      return toString( time[5] ) << toString( time[4] ) << toString( time[3] );
    }

    std::string dati::date( std::string tz = "Europe/London", std::string delimitator = "/" )
    {
      std::vector<int> time = wikipp::libs::dati::dateTime( tz );
      return toString( time[3] ) << delimitator << toString( time[4] ) << delimitator << toString( time[5] );
    }

    std::string dati::time( std::string tz = "Europe/London", std::string format = "HH:MM:SS", std::string gap = "0", std::string delimitator = "/" )
    {
      std::vector<int> time = wikipp::libs::dati::dateTime( tz );
      return toString( time[2] ) << delimitator << toString( time[1] ) << delimitator << toString( time[0] );
    }*/
  }
}

#endif

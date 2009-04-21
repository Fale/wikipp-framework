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

#ifndef WIKIPP_WIKI_IMAGES_H
#define WIKIPP_WIKI_IMAGES_H

#include <iostream>
#include <string>

#include <boost/regex.hpp>

#include "../http/http.h"
#include "../http/wget.h"
#include "../libs/convert.h"
#include "read.h"

namespace wikipp
{
  namespace wiki
  {
    /**
     * Class that takes care about the images.
     *
     * @author Fabio Alessandro Locati
     */
    class images
    {
      public:
        /**
        * Function that will return to you the url to the image linked by a Image: page.
        *
        * @code
        * std::cout << wikipp::wiki::images::getImageUrl( "en.wikipedia.org", "test.jpg" ) << std::endl;
        * @endcode
        *
        * @param site The url of the project (ie: en.wikipedia.org)
        * @param image The name of the image (ie: test.jpg)
        * @return The second part of the Image Url (the url of the image will
        * be like: http://upload.wikimedia.org/{URL given by the function}).
        */
        static std::string getImageUrl( std::string, std::string );

        /**
         * Function that will return to you the wiki text of an Image: page.
         *
         * @code
         * std::cout << wikipp::wiki::images::getImageData( "en.wikipedia.org", "test.jpg" ) << std::endl;
         * @endcode
         *
         * @param site The url of the project (ie: en.wikipedia.org)
         * @param image The name of the image (ie: test.jpg)
         * @return The wiki text of the Image: page.
         */
        static std::string getImageData( std::string, std::string );

        /**
         * Function that will download an image and return you the name of the image.
         *
         * @code
         * std::cout << wikipp::wiki::images::download( "en.wikipedia.org", "test.jpg" ) << std::endl;
         * @endcode
         *
         * @param site The url of the project (ie: en.wikipedia.org)
         * @param image The name of the image (ie: test.jpg)
         * @return The name of the downloaded image.
         */
        static std::string download( std::string, std::string );

        /**
         * Function that will remove a downloaded image.
         *
         * @code
         * wikipp::wiki::images::remove( "test.jpg" );
         * @endcode
         *
         * @param image The name of the image (ie: test.jpg)
         */
        static bool remove( std::string );

        /**
         * Function that will return the SHA1 of an image.
         *
         * @code
         * std::cout << wikipp::wiki::images::sha( "en.wikipedia.org", "test.jpg" ) << std::endl;
         * @endcode
         *
         * @param site The url of the project (ie: en.wikipedia.org)
         * @param image The name of the image (ie: test.jpg)
         * @return The SHA of the image.
         */
        static std::string sha( std::string, std::string );

        /**
         * Function that will verify the presence of an image.
         *
         * @code
         * std::cout << wikipp::wiki::images::verifyPresence( "en.wikipedia.org", "test.jpg" ) << std::endl;
         * @endcode
         *
         * @param site The url of the project (ie: en.wikipedia.org)
         * @param image The name of the image (ie: test.jpg)
         * @return 1 if the image is present, 0 if it isn't
         */
        static bool verifyPresence( std::string, std::string );

        /**
         * Function that verify the equality of two images.
         *
         * @code
         * std::cout << wikipp::wiki::images::verifyEquality( "en.wikipedia.org","test.jpg","commons.wikimedia.org","test.jpg" ) << std::endl;
         * @endcode
         *
         * @param fSite The url of the project (ie: en.wikipedia.org) (1st Image)
         * @param fImage The name of the image (ie: test.jpg) (1st Image)
         * @param sSite The url of the project (ie: en.wikipedia.org) (2nd Image)
         * @param sImage The name of the image (ie: test.jpg) (2nd Image)
         * @return 1 if the two images are equal, 0 if are different
         */
        static bool verifyEquality( std::string, std::string, std::string, std::string );

        /**
         * Function that will return the OTRS number
         *
         * @code
         * std::cout << wikipp::wiki::images::otrs( data ) << std::endl;
         * @endcode
         *
         * @param data The wiki source of the page
         * @return The ORTS number. 0 if OTRS is not available.
         */
        static int otrs( std::string );

        /**
         * Function that will return the OTRS number
         *
         * @code
         * std::cout << wikipp::wiki::images::otrs( "en.wikipedia.org", "test.jpg" ) << std::endl;
         * @endcode
         *
         * @param site The url of the project (ie: en.wikipedia.org)
         * @param image The name of the image (ie: test.jpg)
         * @return The ORTS number. 0 if OTRS is not available.
         */
        static int otrs( std::string, std::string );

/*        static bool upload( std::string image, std::string upname = "default", std::string site = "commons.wikimedia.org", bool verify = 1 )
        {
          std::string postData( );
          std::string data( http::http::post( site, "wiki/Special:Upload", postData ) );
        }*/
    };
  }
}
#endif

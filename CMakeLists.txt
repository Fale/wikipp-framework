# The name of our project is "HELLO". CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project (WIKI)

#include(${WIKI_SOURCE_DIR}/FindBoost.cmake)

set(BUILD_SHARED_LIBS ON)

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE( Boost 1.36 COMPONENTS date_time regex system)

set(CMAKE_THREAD_LIBS_INIT)
add_definitions(-g)
#ADD_DEFINITIONS(-Wall -O2)

link_directories ( ${WIKI_LIBRARY_DIRS} )

link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

include_directories(${WIKI_SOURCE_DIR} ${BOOST_INCLUDE_PATH})

add_subdirectory (http)
add_subdirectory (libs)
add_subdirectory (wiki)
add_subdirectory (extended)
add_subdirectory (tests)

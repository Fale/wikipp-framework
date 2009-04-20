link_directories (${BOOST_INCLUDE_PATH})

add_executable (wikipp_test_http http.cpp)
add_executable (wikipp_test_http_backend_asio asio.cpp)
add_executable (wikipp_test_http_backend_wget wget.cpp)

install(TARGETS wikipp_test_http
                wikipp_test_http_backend_asio
                wikipp_test_http_backend_wget
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

target_link_libraries (wikipp_test_http wikipp_http)
target_link_libraries (wikipp_test_http_backend_asio wikipp_http_backend_asio)
target_link_libraries (wikipp_test_http_backend_wget wikipp_http_backend_wget)
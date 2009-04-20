add_library (wikipp_http SHARED http.cpp)
add_library (wikipp_http_backend_asio SHARED asio.cpp)
add_library (wikipp_http_backend_wget SHARED wget.cpp)

install(FILES asio.h
              http.h
              wget.h
DESTINATION include/wiki++/http/
COMPONENT Devel)

install(TARGETS wikipp_http
                wikipp_http_backend_asio
                wikipp_http_backend_wget
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

target_link_libraries(wikipp_http wikipp_http_backend_asio wikipp_http_backend_wget)
target_link_libraries(wikipp_http_backend_asio libboost_thread-gcc43-mt-1_38.so libboost_regex-gcc43-mt-1_38.so libboost_system-gcc43-mt-1_38.so)

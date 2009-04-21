add_library (wikipp_wiki_categories SHARED categories.cpp)
add_library (wikipp_wiki_edittoken SHARED edittoken.cpp)
add_library (wikipp_wiki_images SHARED images.cpp)
add_library (wikipp_wiki_login SHARED login.cpp)
add_library (wikipp_wiki_move SHARED move.cpp)
add_library (wikipp_wiki_read SHARED read.cpp)
add_library (wikipp_wiki_relatedpages SHARED relatedpages.cpp)
add_library (wikipp_wiki_user SHARED user.cpp)
add_library (wikipp_wiki_write SHARED write.cpp)

install(FILES categories.h
              edittoken.h
              images.h
              login.h
              move.h
              read.h
              relatedpages.h
              user.h
              write.h
DESTINATION include/wiki++/wiki/
COMPONENT Devel)

install(TARGETS wikipp_wiki_categories
                wikipp_wiki_edittoken
                wikipp_wiki_images
                wikipp_wiki_login
                wikipp_wiki_move
                wikipp_wiki_read
                wikipp_wiki_relatedpages
                wikipp_wiki_user
                wikipp_wiki_write
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

target_link_libraries(wikipp_wiki_categories wikipp_http)
target_link_libraries(wikipp_wiki_edittoken wikipp_http)
target_link_libraries(wikipp_wiki_images wikipp_http wikipp_libs_convert wikipp_wiki_read wikipp_http_backend_wget)
target_link_libraries(wikipp_wiki_login wikipp_http_backend_wget wikipp_http_backend_asio wikipp_libs_dati)
target_link_libraries(wikipp_wiki_move libboost_regex-gcc43-mt-1_38.so wikipp_http wikipp_libs_urlencode)
target_link_libraries(wikipp_wiki_read wikipp_http wikipp_libs_urlencode)
target_link_libraries(wikipp_wiki_relatedpages libboost_regex-gcc43-mt-1_38.so)
target_link_libraries(wikipp_wiki_user libboost_regex-gcc43-mt-1_38.so wikipp_http wikipp_libs_convert)
target_link_libraries(wikipp_wiki_write libboost_regex-gcc43-mt-1_38.so wikipp_http wikipp_libs_urlencode wikipp_wiki_edittoken wikipp_wiki_read)
add_executable (wikipp_test_wiki_categories categories.cpp)
add_executable (wikipp_test_wiki_edittoken edittoken.cpp)
add_executable (wikipp_test_wiki_images images.cpp)
add_executable (wikipp_test_wiki_login login.cpp)
add_executable (wikipp_test_wiki_move move.cpp)
add_executable (wikipp_test_wiki_read read.cpp)
add_executable (wikipp_test_wiki_relatedpages relatedpages.cpp)
add_executable (wikipp_test_wiki_user user.cpp)
add_executable (wikipp_test_wiki_write write.cpp)

install(TARGETS wikipp_test_wiki_categories
                wikipp_test_wiki_edittoken
                wikipp_test_wiki_images
                wikipp_test_wiki_login
                wikipp_test_wiki_move
                wikipp_test_wiki_read
                wikipp_test_wiki_relatedpages
                wikipp_test_wiki_user
                wikipp_test_wiki_write
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

target_link_libraries (wikipp_test_wiki_categories wikipp_wiki_categories)
target_link_libraries (wikipp_test_wiki_edittoken wikipp_wiki_login wikipp_wiki_edittoken)
target_link_libraries (wikipp_test_wiki_login wikipp_wiki_login wikipp_wiki_edittoken)
target_link_libraries (wikipp_test_wiki_images wikipp_wiki_images)
target_link_libraries (wikipp_test_wiki_move wikipp_wiki_move wikipp_wiki_login)
target_link_libraries (wikipp_test_wiki_read wikipp_wiki_read)
target_link_libraries (wikipp_test_wiki_relatedpages wikipp_wiki_relatedpages)
target_link_libraries (wikipp_test_wiki_user wikipp_wiki_user)
target_link_libraries (wikipp_test_wiki_write wikipp_wiki_write wikipp_wiki_login)

#add_test (wikipp_test_wiki_categories)
#add_test (wikipp_test_wiki_edittoken)
#add_test (wikipp_test_wiki_images)
#add_test (wikipp_test_wiki_login)
#add_test (wikipp_test_wiki_move)
#add_test (wikipp_test_wiki_read)
#add_test (wikipp_test_wiki_relatedpages)
#add_test (wikipp_test_wiki_user)
#add_test (wikipp_test_wiki_write)

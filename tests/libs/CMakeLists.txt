add_executable (wikipp_test_libs_convert convert.cpp)
add_executable (wikipp_test_libs_dati dati.cpp)
add_executable (wikipp_test_libs_languages languages.cpp)
add_executable (wikipp_test_libs_prgdata prgdata.cpp)
add_executable (wikipp_test_libs_urlencode urlencode.cpp)

install(TARGETS wikipp_test_libs_convert
                wikipp_test_libs_dati
                wikipp_test_libs_languages
                wikipp_test_libs_prgdata
                wikipp_test_libs_urlencode
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

target_link_libraries (wikipp_test_libs_dati wikipp_libs_dati)
target_link_libraries (wikipp_test_libs_languages wikipp_libs_languages)
target_link_libraries (wikipp_test_libs_prgdata wikipp_libs_prgdata)
target_link_libraries (wikipp_test_libs_urlencode wikipp_libs_urlencode)
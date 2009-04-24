add_library (wikipp_libs_dati SHARED dati.cpp)
add_library (wikipp_libs_languages SHARED languages.cpp)
#add_library (wikipp_libs SHARED libs.cpp)
add_library (wikipp_libs_prgdata SHARED prgdata.cpp)
add_library (wikipp_libs_urlencode SHARED urlencode.cpp)

install(FILES config.h
              convert.h
              dati.h
              prgdata.h
              urlencode.h
              languages.h
              libs.h
DESTINATION include/wiki++/libs/
COMPONENT Devel)

install(TARGETS wikipp_libs_dati
                wikipp_libs_languages
                wikipp_libs_prgdata
                wikipp_libs_urlencode
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

target_link_libraries(wikipp_libs_dati libboost_date_time-gcc43-mt-1_38.so)
target_link_libraries(wikipp_libs_languages wikipp_libs_urlencode libboost_regex-gcc43-mt-1_38.so)
target_link_libraries(wikipp_libs_prgdata libboost_regex-gcc43-mt-1_38.so)
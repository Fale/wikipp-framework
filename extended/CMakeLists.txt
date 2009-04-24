add_library (wikipp_extended_currency SHARED currency.cpp)
add_library (wikipp_extended_index SHARED index.cpp)
add_library (wikipp_extended_storm SHARED storm.cpp)

install(FILES currency.h
              index.h
              strom.h
DESTINATION include/wiki++/extended/
COMPONENT Devel)

install(TARGETS wikipp_extended_currency
                wikipp_extended_index
                wikipp_extended_storm
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

target_link_libraries(wikipp_extended_currency libboost_regex-gcc43-mt-1_38.so wikipp_http)
target_link_libraries(wikipp_extended_index libboost_regex-gcc43-mt-1_38.so wikipp_http)
target_link_libraries(wikipp_extended_storm wikipp_libs_dati wikipp_libs_languages wikipp_wiki_write wikipp_wiki_move wikipp_wiki_relatedpages)

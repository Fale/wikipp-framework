add_library (wikipp_extended_currency SHARED currency.cpp)
add_library (wikipp_extended_index SHARED index.cpp)

install(FILES currency.h
              index.h
DESTINATION include/wiki++/extended/
COMPONENT Devel)

install(TARGETS wikipp_extended_currency
                wikipp_extended_index
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

target_link_libraries(wikipp_extended_currency libboost_regex-gcc43-mt-1_38.so wikipp_http)
target_link_libraries(wikipp_extended_index libboost_regex-gcc43-mt-1_38.so wikipp_http)

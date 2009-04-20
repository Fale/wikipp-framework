add_executable (wikipp_test_extended_currency currency.cpp)
add_executable (wikipp_test_extended_index index.cpp)

install(TARGETS wikipp_test_extended_currency
                wikipp_test_extended_index
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

target_link_libraries (wikipp_test_extended_currency wikipp_extended_currency wikipp_libs_dati)
target_link_libraries (wikipp_test_extended_index wikipp_extended_index)
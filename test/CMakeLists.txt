include(GoogleTest)


add_executable(tmp_test tmp_test.cc)
target_link_libraries(tmp_test gtest gtest_main pthread)

add_executable(timer_test timer_test.cc)
target_link_libraries(timer_test yynetlib gtest gtest_main pthread)

add_test(tmp tmp_test)
add_test(timer timer_test)





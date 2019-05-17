include(GoogleTest)


add_executable(helloworld_test tmp_test.cc)
target_link_libraries(helloworld_test gtest gtest_main pthread)

add_executable(timer_test timer_test.cc)
target_link_libraries(timer_test yynetlib gtest gtest_main pthread)

add_test(HelloWorld helloworld_test)
add_test(Timer timer_test)





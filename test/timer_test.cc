#include "timer.h"

#include <gtest/gtest.h>
#include <functional>
#include <iostream>
#include <thread>
#include <sys/time.h>

namespace yynet{
namespace {

int64_t TimevalToMicroSec(timeval* tv) {
    if (tv == nullptr) {
        return 0;
    }
    return tv->tv_sec * 1000000 + tv->tv_usec; 
}

class TimerTest : public ::testing::Test {
protected:
    std::function<void()> callback;

    void SetUp() override {
        callback = [] { std::cout << "Hello World\n"; };    
    }
};

TEST_F(TimerTest, Basic) {
    timeval start_time, end_time;
    EXPECT_EQ(gettimeofday(&start_time, 0), 0);
    std::thread thread([&]{
        Timer timer(callback, 5);
    });
    thread.join();
    EXPECT_EQ(gettimeofday(&end_time, 0), 0);
    int64_t duration = TimevalToMicroSec(&end_time) - TimevalToMicroSec(&start_time);
    EXPECT_LT(duration, 5500000);
    EXPECT_GT(duration, 4500000);
}


}   // namespace
}   //namespace yynet
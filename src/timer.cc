#include "timer.h"

#include <chrono>
#include <thread>

namespace yynet {

Timer::Timer(std::function<void()> callback, int delay) {
    std::this_thread::sleep_for(std::chrono::seconds(delay));
    callback();
}

}   // namespace yynet
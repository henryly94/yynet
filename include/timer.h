#ifndef _YYNET_TIMER_H_INCLUDED_
#define _YYNET_TIMER_H_INCLUDED_

#include <functional>

namespace yynet {

class Timer {
public:
    Timer() = delete;
    Timer& operator=(const Timer&) = delete;
    
    explicit Timer(std::function<void()> callback, int delay);

};

}

#endif //_YYNET_TIMER_H_INCLUDED_
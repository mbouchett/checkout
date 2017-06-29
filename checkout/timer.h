/* 
 * File:   timer.h
 * Author: mark
 *
 * Created on June 28, 2017, 10:08 PM
 */

#ifndef TIMER_H
#define TIMER_H
#include <time.h>       //include system time

class timer {
public:
    timer();
private:
    int start;
    int elapsedSeconds;
    int interval;
    
};

#endif /* TIMER_H */


#include <iostream>     //console Input/Output
#include <time.h>       //include system time

using namespace std;

int main(void)
{
    int const SIMTIME = 60;        //Simulation runtime in seconds 900 = 15min
    time_t timeBeg = time(0);       //used for the timer
    time_t timeEnd = time(0);       //used for the timer
    
    while((timeEnd-timeBeg) <= SIMTIME){
        
        
        timeEnd = time(0);
    };
    
    
    cout << "Simulation finished - Runtime: " << (SIMTIME / 60) << " minutes.";
    return 0;
}


#include <iostream>     //console Input/Output
#include <time.h>       //include system time

using namespace std;

int main(void)
{
    int const SIMTIME = 480;        //Simulation runtime in seconds 900 = 15min
    time_t timeBeg = time(0);       //used for the timer
    time_t timeEnd = time(0);       //used for the timer
    int elapsedSecs = timeEnd-timeBeg;
    int oldSecs = elapsedSecs;
    int hour = 10;
    
    cout << "The store is open!\n------------------\n";
    cout << "The time is now " << hour <<":00\n";
    
    while(elapsedSecs <= SIMTIME){
        elapsedSecs = timeEnd-timeBeg;
        if(elapsedSecs > oldSecs && (elapsedSecs % 60) == 0){
            //one minute real time / one hour sim time has passed
            oldSecs = elapsedSecs;
            hour++;
            cout << "The time is now " << hour <<":00\n"; 
        }
        
        timeEnd = time(0);
    };
    
    
    cout << "Simulation finished - Runtime: " << (SIMTIME / 60) << " minutes.";
    return 0;
}


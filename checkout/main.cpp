#include <iostream>     //console Input/Output
#include <time.h>       //include system time

using namespace std;

int main(void)
{
    //1 second real time = 1 minute simulation time;
    int const SIMTIME = 480;        //Simulation runtime in minutes 480 = 8 hrs
    int const DISP_FREQ = 10;       //real time seconds/sim-time minutes display
    time_t timeBeg = time(0);       //used for the timer
    time_t timeEnd = time(0);       //used for the timer
    int elapsedSecs = timeEnd-timeBeg;
    int oldSecs1 = elapsedSecs;
    int oldSecs2 = elapsedSecs;
    
    int hour = 10;
    int minutes = 0;
    
    cout << "The store is open!\n------------------\n";
    cout << "The time is now " << hour <<":00\n";
    
    while(elapsedSecs <= SIMTIME){
        elapsedSecs = timeEnd-timeBeg;
        
        // hour keeper
        if(elapsedSecs > oldSecs1 && (elapsedSecs % 60) == 0){
            //one minute real time / one hour sim-time has passed
            oldSecs1 = elapsedSecs;
            hour++; 
        }
        
        // display timer
        if(elapsedSecs > oldSecs2 && (elapsedSecs % DISP_FREQ) == 0){
            oldSecs2 = elapsedSecs;
            minutes += DISP_FREQ;
            if(minutes > 59) minutes = 0; 
            if(minutes < 10){
                cout << hour << ":0" << minutes; 
                cout << " - No register open No customers in line\n";
            }else{
                cout << hour << ":" << minutes;
                cout << " - No register open No customers in line\n";
            }
        }
        
        // event timer 
        
        
        timeEnd = time(0);
    };
    
    
    cout << "Simulation finished - Runtime: " << (SIMTIME / 60) << " minutes.";
    return 0;
}


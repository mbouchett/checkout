#include <iostream>     //console Input/Output
#include <time.h>       //include system time
#include "Store.h"
#include <time.h>

using namespace std;
// function prototypes
bool newCustomerCuesUp();
int getWait(int);
int customersEnterStore(int);

int main(void)
{
    srand(time(NULL));              //seed the random generator
    //1 second real time = 1 minute simulation time;
    int const SIMTIME = 480;        //Simulation runtime in minutes 480 = 8 hrs
    int const DISP_FREQ = 10;       //real time seconds/sim-time minutes display

    time_t timeBeg = time(0);       //used for the timer
    time_t timeEnd = time(0);       //used for the timer
    int elapsedSecs = timeEnd-timeBeg;
    int oldSecs1 = elapsedSecs;     //tracks elapsed seconds
    int oldSecs2 = elapsedSecs;     //tracks elapsed seconds
    int oldSecs3 = elapsedSecs;     //tracks elapsed seconds
    int wait = 0;                   // holds wait time
    
    int hour = 10;
    int minutes = 0;
    
    Store store(200);
    
    
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
                cout << " - " << store.getRegistersOpen() 
                        << " register open " << store.custCount() 
                        << " customers in line\n";
            }else{
                cout << hour << ":" << minutes;
                cout << " - " << store.getRegistersOpen()
                        << " registers open " << store.custCount() 
                        << " customers in line\n";
            }
        }
        
        // event timer / each second second = minute
        if(elapsedSecs > oldSecs3){
            oldSecs3 = elapsedSecs;

                // New customer cues?
                if(newCustomerCuesUp())
                    wait = getWait(hour);
                    if(!store.newCustomer(wait))
                        cout << "the store is full\n";

            
            // elapse time
            store.elapseTime();
            //store.display();
            store.dispLines();
        }
        
        timeEnd = time(0);
    };
    
    store.dispStoreStatus();
    cout << "Simulation finished - Runtime: " << (SIMTIME / 60) 
            << " minutes real time - 8 hours simulation time.";
    return 0;
}

/*
 * checked every sim-minute the
 * chance that a new customer got in line
*/
bool newCustomerCuesUp(){
    int odds = rand() % 100 + 1;
    if (odds > 30)          // 70% chance of a new customer this sim-minute
        return true;
    return false;
}

/*
 * calculates a a customer's wait time in sim-minutes
 * based on peak or off peak tine of day
 */
int getWait(int timeOfDay){
    int wait = 0;       //wait in minutes
    int p = rand() % 100 + 1;
    // peak hours noon to 1:00p
    if(timeOfDay == 12){
        if(p > 5)
            wait = rand() % 5 + 5;  // 5 to 10 minute wait
        else
            wait = rand() % 3 + 1;  // 1 to 3 minute wait
    }else{ //off peak
        if(p > 25)
            wait = rand() % 3 + 1;  // 1 to 3 minute wait
        else
            wait = rand() % 5 + 5;  // 5 to 10 minute wait
    }
}

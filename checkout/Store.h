/* 
 * File:   Store.h
 * Author: mark
 *
 * Created on August 15, 2017, 11:27 AM
 */

#ifndef STORE_H
#define STORE_H
#include "Customer.h"
#include <array>
#include <iostream>
#include <list>
#include <time.h>
#include <map>
#include <iomanip>

struct Reg{                         //Represents a register
    bool moved;                     //tracks If line has moved in this cycle                 
    int custInLine;                 //number of customers at this register
};
struct Line{                       //Represents a line         
    int custInLine;                 //number of customers in the line
    int totWait;                    //total wait in time for the line
};

const int AVAILREGS = 9;            // Number of Available Registers

class Store{
private:
    int CAPACITY;                   // Store Occupancy Limit
    Customer* cust;                 // Main Customer Array
    Reg reg[AVAILREGS];             // Array of registers
    std::list<Customer> active;     // Active Customers
    int openReg();                  // returns the number of an open register
    void initializeRegs();          // initialize registers
    void resetMoved();              // clears the moved marker for the cycle
    std::map<int, Line> lMap;       // hash table of line data
    
public:
    Store();                        // no param constructor
    Store(int);                     // constructor with capacity
    
    void display();
    void elapseTime();
    int custCount();
    bool newCustomer(int);
    void dispStoreStatus();
    int getRegistersOpen();
    void dispLines();
};


#endif /* STORE_H */


/* 
 * File:   Customer.h
 * Author: mark
 *
 * Created on August 2, 2017, 10:20 PM
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer{
private:
    int cashier;
    int timeInLine; // in seconds
public:
    Customer();             // No-Param constructor
    Customer(int, int);     // Constructor cashier, time
    void killTime();        // decrement time
    //setters
    void setCashier(int);      // set the cashier
    void setTime(int);   // sets the time that the customer will take in line
    //getters
    int getCashier();       // returns the currently set cashier
    int getTime();     // returns the remaining time in line 
   
    
};
#endif /* CUSTOMER_H */
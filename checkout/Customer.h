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
    Customer();         // No-Param constructor
    Customer(int, int); // Constructor cashier, time
    ~Customer();        // destructor
    void killTime();    // decrement time
};
#endif /* CUSTOMER_H */
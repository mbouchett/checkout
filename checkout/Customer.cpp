#include "Customer.h"

Customer::Customer(){
    cashier = 0;
    timeInLine = 0;
}

Customer::Customer(int cash, int time){
    cashier = cash;
    timeInLine = time; 
}

void Customer::killTime(){
    if(timeInLine > 0)
        timeInLine--;
}

void Customer::setCashier(int c){
    cashier = c;
}

void Customer::setTime(int t){
    timeInLine = t;
}

int Customer::getCashier(){
    return cashier;
}

int Customer::getTime(){
    return timeInLine;
}
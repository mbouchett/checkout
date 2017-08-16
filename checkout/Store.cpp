#include "Store.h"

Store::Store(){
    CAPACITY = 100;
    cust = new Customer[CAPACITY];
    initializeRegs();
    srand(time(NULL));
}

Store::Store(int cap){
    CAPACITY = cap;
    cust = new Customer[CAPACITY];
    initializeRegs();
    srand(time(NULL));
}
/**
 * update the display 
 * @param c -customer vector
 */
void Store::display(){
    std::cout << custCount()<< " Customers in line. " << getRegistersOpen() 
            << " Registers Open." << std::endl;
}

/**
 * cycle through the customer list and decrement time
 * delete customer if expired
 * @param c -customer vector
 */
void Store::elapseTime(){
    resetMoved();
    bool m = false;
    int r;
    for(int i = 0; i < CAPACITY; i++){
        r = cust[i].getCashier();
        m = reg[r].moved;
        if(cust[i].getTime() > 0 && !m){
            cust[i].killTime();
            reg[r].moved = true;
            // if customer done reduce the line
            if(cust[i].getTime() < 1)
                reg[cust[i].getCashier()].custInLine--;
        }
    }
}

int Store::custCount(){
    int count = 0;
    for(int i = 0; i < CAPACITY; i++){
        if (cust[i].getTime() > 0)
            count++;
    }
    return count;
}

bool Store::newCustomer(int time){
    // find free customer
    for(int i = 0; i < CAPACITY; i++){
        if(cust[i].getTime() == 0){
            cust[i].setTime(time);
            // find a free register
            cust[i].setCashier(openReg());
            return true;
        }
    }
    std::cout << "The Store is at capacity. Close the doors!\n";
    return false; // the store is at capacity 
}

void Store::dispStoreStatus(){
    active.clear();
    //add active customers to the list
    for(int i = 0; i < CAPACITY; i++){
        if (cust[i].getTime() > 0){
            active.push_back(cust[i]);
        }
    }
    int custNum = 0;
    //iterate over the list
    for(auto it = active.begin(); it != active.end(); it++){
        custNum++;
        std::cout << "Customer #" << custNum << " has " << it->getTime() 
                << " Minutes Left\n";
    }
}

int Store::openReg(){
    for(int i = 0; i < AVAILREGS; i++){
        if(reg[i].custInLine < 6){
            reg[i].custInLine++;
            return i;
        }
    }
    std::cout << "Registers are over capacity\n";
    int randReg = rand() % 9;
    reg[randReg].custInLine++;
    return randReg;
}

void Store::initializeRegs(){
    for(int i = 0; i < AVAILREGS; i++){
        reg[i].custInLine = 0;
        reg[i].moved = false;
    }
}

int Store::getRegistersOpen(){
    int rOpen = 0;
    for(int i = 0; i < AVAILREGS; i++)
        if(reg[i].custInLine > 0)
            rOpen++;
    return rOpen;
}

void Store::dispLines(){
    lMap.clear();
    Line l;
    for(int i = 0; i < AVAILREGS; i++){
        l.totWait = 0;
        if(reg[i].custInLine > 0){
            l.custInLine = reg[i].custInLine;
            for(int j = 0; j < CAPACITY; j++){ 
                if(cust[j].getCashier() == i){
                    int t = cust[j].getTime();
                    l.totWait += t;
                }
            }  
            lMap[i] = l;
        }
        
        
       // std:: cout << i << " - " << l.custInLine << " - " << l.totWait << std::endl;
    }
    
    std::map<int, Line>::iterator it;
    std::cout << "Registers open: ";
    for(it = lMap.begin(); it != lMap.end(); it++){
        l = it->second;
        
        std::cout << "#" << (it->first) + 1
                  << "(" << l.custInLine << ")"
                  << " " << std::setw(2) << l.totWait << "min| ";
    }
    std::cout << std::endl;
}

void Store::resetMoved(){
    for(int i = 0; i < AVAILREGS; i++)
        reg[i].moved = false;
}
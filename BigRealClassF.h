#include "BigDecClass.h"
#include <regex>
#include<iostream>
#include <string>


class BigReal {
private:
    string real_num;
    char signn;
public:
    BigReal ();
    BigReal (double realNumber);
    BigReal (string realNumber);
    void ret();
    BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& other);  //copy constructor
    BigReal (BigReal&& other); // Move constructor
    BigReal& operator= (BigReal& other); //copy assignment
    BigReal& operator= (BigReal&& other); // Move assignment

    
};

#include "BigRealClassF.h"
//#include "BigDecClass.h"
#include<iostream>

using namespace std;


BigReal::BigReal() {
    real_num = "0.0";
    signn ='+';
}

BigReal::BigReal(string realNumber) {

    regex rej_pattern("[+-]?[0-9]+(\\.[0-9]+)?");

    if(regex_match(realNumber,rej_pattern)) {
        if(realNumber[0] =='-') {
            signn='-';
            realNumber.erase(realNumber.begin());
        }
        else {
            signn='+';
            if(realNumber[0]=='+')
                realNumber.erase(realNumber.begin());
        }

        string temp="";
        bool t=0;
        for(long long i=0; i<realNumber.size() ; i++){
            if(realNumber[i]=='0'&& t==0 ){
                continue;
            }
            else {
                t=1;
                temp+=realNumber[i];
            }

        }
        if(temp[0]=='.'){
            temp='0'+temp;
        }
        real_num=temp;
    }

    else
        throw("error name");


}


void BigReal::ret() {
    cout<<real_num<<endl;
    cout<<signn<<endl;

}

BigReal::BigReal(BigDecimalInt bigInteger) {
    real_num=bigInteger.getNumber();
    signn=bigInteger.sign();

}

BigReal::BigReal(double realNumber) {
    if(realNumber>=0)
        signn='+';
    else signn='-';
    real_num=to_string(abs(realNumber));

}

BigReal::BigReal(const BigReal &other) {
    real_num=other.real_num;
    signn=other.signn;

}

BigReal &BigReal::operator=(BigReal &other) {
    real_num=other.real_num;
    signn=other.signn;
    return *this;

}

BigReal::BigReal(BigReal &&other) {
    this->real_num =other.real_num;
    this->signn=other.signn;
}

BigReal &BigReal::operator=(BigReal &&other) {
    this->real_num =other.real_num;
    other.real_num=" ";
    this->signn=other.signn;
    return *this;

}



/*
 * ZFraction.cpp
 *
 *  Created on: 14 nov. 2014
 *      Author: seb
 */

#include "ZFraction.hpp"


/***Public methods***/
bool ZFraction::equal(ZFraction const& a) const{
    return (num==a.num && den==a.den); //because the fraction is always simplified
}

bool ZFraction::smaller(ZFraction const& a) const{
    return (num*a.den < den*a.num);
}

ZFraction ZFraction::addition(ZFraction const& a) const{
    ZFraction b(num*a.den+den*a.num, den*a.den);
    return b;
}

ZFraction ZFraction::multiplication(ZFraction const& a) const{
    ZFraction b(num*a.num, den*a.den);
    return b;
}

void ZFraction::display(std::ostream &flux) const{
    if(den==1) flux << num;
    else flux << num << "/" << den;
}


/***Private methods***/
void ZFraction::simplify(){
    int out = pgcd(num, den);
    num /= out;
    den /= out;
}


/***Operators***/
ZFraction& ZFraction::operator+=(ZFraction const& a){
    addition(a);
    return *this;
}

bool operator==(ZFraction const& a, ZFraction const& b){
    return a.equal(b);
}

bool operator!=(ZFraction const& a, ZFraction const& b){
    return !a.equal(b); //!(a==b)
}

bool operator<(ZFraction const& a, ZFraction const& b){
    return a.smaller(b);
}

bool operator>(ZFraction const& a, ZFraction const& b){
    return b.smaller(a);
}

bool operator<=(ZFraction const& a, ZFraction const& b){
    return !b.smaller(a); //!(a>b)
}

bool operator>=(ZFraction const& a, ZFraction const& b){
    return !a.smaller(b); //!(a<b)
}

ZFraction operator+(ZFraction const& a, ZFraction const& b){
    return a.addition(b);
}

ZFraction operator*(ZFraction const& a, ZFraction const& b){
    return a.multiplication(b);
}

std::ostream& operator<<(std::ostream &flux, ZFraction const& a){
    a.display(flux);
    return flux;
}


/***Extern functions***/
int pgcd(int a, int b){
    while (b != 0){
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}

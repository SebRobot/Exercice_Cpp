/*
 * ZFaction.hpp
 *
 *  Created on: 14 nov. 2014
 *      Author: seb
 */

#ifndef ZFRACTION_HPP_
#define ZFRACTION_HPP_

#include <iostream>

class ZFraction{
public:
    ZFraction(int a, int b):num(a),den(b){simplify();};
    ZFraction(int a):num(a),den(1){};
    ZFraction():num(0),den(1){};

    bool equal(ZFraction const& a) const; //num/den == a ? true : false
    bool smaller(ZFraction const& a) const; //num/den < a ? true : false
    ZFraction addition(ZFraction const& a) const;
    ZFraction multiplication(ZFraction const& a) const;
    void display(std::ostream &flux) const;

    ZFraction& operator+=(ZFraction const& a);

private:
    void simplify();

private:
    int num;
    int den;


};

bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);
ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
std::ostream& operator<<(std::ostream &flux, ZFraction const& a);



int pgcd(int a, int b);



#endif /* ZFRACTION_HPP_ */

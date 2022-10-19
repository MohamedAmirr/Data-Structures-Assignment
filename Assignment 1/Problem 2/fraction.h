#ifndef MAIN_CPP_FRACTION_H
#define MAIN_CPP_FRACTION_H

#include<iostream>

using namespace std;

class fraction {
private:
    int numo;       // numerator
    int denmo;      // denominator
    char x = '/';
public:
    fraction();

    fraction(int n, int d);

    fraction operator+(fraction &obj);

    fraction operator-(fraction &obj);

    fraction operator*(fraction &obj);

    fraction operator/(fraction &obj);

    bool operator<(fraction &obj);

    bool operator>(fraction &obj);

    bool operator<=(fraction &obj);

    bool operator>=(fraction &obj);

    bool operator==(fraction &obj);

    void reducing_fraction();

    int getDenmo();

    int getnumo();

    friend istream &operator>>(istream &is, fraction &obj);

    friend ostream &operator<<(ostream &os, fraction &obj);

    ~fraction();
};


#endif //MAIN_CPP_FRACTION_H

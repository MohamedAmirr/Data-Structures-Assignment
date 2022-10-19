//
// Created by mohamed on ٢٧‏/٤‏/٢٠٢٢.
//

#include "fraction.h"


fraction::fraction() {

}

fraction::fraction(int n, int d) {
    numo = n;
    denmo = d;
}

fraction fraction::operator+(fraction &obj) {
    fraction temp;
    temp.numo = (numo * obj.denmo) + (obj.numo * denmo);
    temp.denmo = (denmo * obj.denmo);
    return temp;
}

fraction fraction::operator-(fraction &obj) {
    fraction temp;
    temp.numo = (numo * obj.denmo) - (obj.numo * denmo);
    temp.denmo = (denmo * obj.denmo);
    return temp;
}

fraction fraction::operator*(fraction &obj) {
    fraction temp;
    temp.numo = numo * obj.numo;
    temp.denmo = denmo * obj.denmo;
    return temp;
}

fraction fraction::operator/(fraction &obj) {
    fraction temp;
    temp.numo = numo * obj.denmo;
    temp.denmo = denmo * obj.numo;
    return temp;
}

bool fraction::operator<(fraction &obj) {
    if ((numo != obj.numo && numo < obj.numo) || (numo == obj.numo && denmo > obj.denmo))
        return true;
    else
        return false;
}

bool fraction::operator>(fraction &obj) {
    if (numo != obj.numo && numo > obj.numo || numo == obj.numo && denmo < obj.denmo)
        return true;
    else
        return false;
}

bool fraction::operator<=(fraction &obj) {
    if (numo != obj.numo && numo <= obj.numo || numo == obj.numo && denmo > obj.denmo)
        return true;
    else
        return false;
}

bool fraction::operator>=(fraction &obj) {
    if (numo != obj.numo && numo >= obj.numo || numo == obj.numo && denmo < obj.denmo)
        return true;
    else
        return false;
}

bool fraction::operator==(fraction &obj) {
    if (numo == obj.numo && denmo == obj.denmo)
        return true;
    else
        return false;
}

void fraction::reducing_fraction() {
    int gcd = 1;
    int bigger = max(numo, denmo);
    for (int i = 1; i < bigger; ++i) {
        if (numo % i == 0 && denmo % i == 0)
            gcd = i;
    }
    numo /= gcd;
    denmo /= gcd;
}

int fraction::getDenmo() {
    return denmo;
}

int fraction::getnumo() {
    return numo;
}

istream &operator>>(istream &is, fraction &obj) {
    int newNumo, newDenmo;
    is >> newNumo >> obj.x >> newDenmo;
    if(newDenmo==0){
        throw invalid_argument("Invalid fraction!\n");
    }
    return is;
}

ostream &operator<<(ostream &os, fraction &obj) {
    if (obj.numo == obj.denmo)
        os << 1;
    else
        os << obj.numo << '/' << obj.denmo;
    return os;
}

fraction::~fraction() {
}

//
// Created by mohamed on ٢٦‏/٤‏/٢٠٢٢.
//

#ifndef PROBLEM_3_MATRIX_H
#define PROBLEM_3_MATRIX_H

#include <string>
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

template<class T>
class Matrix {
private:
    T **grid;
    int rows;
    int cols;
public:
    void SetRows(int r);

    void SetCols(int c);

    int GetRows();

    int GetCols();

    void allocate_memory();

    Matrix();


    Matrix(int r, int c);

    Matrix(Matrix<T> &obj);

    Matrix<T> operator+=(const Matrix<T> &obj);

    Matrix<T> operator-=(const Matrix<T> &obj);

    Matrix<T> operator*=(const Matrix<T> &obj);

    template<class u>
    friend ostream &operator<<(ostream &os, const Matrix<u> &);

    template<class u>
    friend istream &operator>>(istream &is, const Matrix<u> &);

    Matrix<T> transpose();

    ~Matrix();
};


#endif //PROBLEM_3_MATRIX_H



#include "Matrix.h"

template<class T>
Matrix<T>::Matrix() {}

template<class T>
void Matrix<T>::SetRows(int r) {
    rows = r;
}

template<class T>
void Matrix<T>::SetCols(int c) {
    cols = c;
}

template<class T>
int Matrix<T>::GetRows() {
    return rows;
}

template<class T>
int Matrix<T>::GetCols() {
    return cols;
}

template<class T>
void Matrix<T>::allocate_memory() {
    grid = new int *[rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new int[cols];
    }
}


template<class T>
Matrix<T>::Matrix(int r, int c) {
    rows = r;
    cols = c;
    allocate_memory();
}

template<class T>
Matrix<T>::Matrix(Matrix<T> &obj) {
    rows = obj.rows;
    cols = obj.cols;
    allocate_memory();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = obj.grid[i][j];
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T> &obj) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] += obj.grid[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator-=(const Matrix<T> &obj) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] -= obj.grid[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator*=(const Matrix<T> &obj) {
    T res[rows][obj.cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < obj.rows; ++k) {
                res[i][j] += (grid[i][k] * obj.grid[k][j]);
            }
        }
    }
    cols=obj.cols;
    allocate_memory();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            grid[i][j]=res[i][j];
        }
    }
    return *this;
}

template<class T>
ostream &operator<<(ostream &os, const Matrix<T> &obj) {
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            os << obj.grid[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

template<class T>
istream &operator>>(istream &is, const Matrix<T> &obj) {
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            is >> obj.grid[i][j];
        }
    }
    return is;
}

template<class T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> temp(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp.grid[j][i] = grid[i][j];
        }
    }
    swap(rows, cols);
    grid = new int *[rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = temp.grid[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++)
        delete[] grid[i];
    delete[] grid;
}

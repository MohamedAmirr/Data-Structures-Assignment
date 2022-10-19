#include "Matrix_Calculator.h"


template<class T>
Matrix_Calculator<T>::Matrix_Calculator() {
    int a;
    int d1 = 0, d2 = 0, dd1 = 1, dd2 = 1;
    cout << "Welcome to Matrix Calculator\n"
            "1- Perform Matrix Addition\n"
            "2- Perform Matrix Subtraction\n"
            "3- Perform Matrix Multiplication\n"
            "4- Matrix Transpose" << '\n';
    cin >> a;
    cout << "Enter Dimensions of first Matrix:\n";
    cin >> d1 >> d2;
    cout << "Enter Dimensions of second Matrix:\n";
    cin >> dd1 >> dd2;
    if ((d1 != dd1 or d2 != dd2) and (a == 1 or a == 2)) {
        while (d1 != dd1 or d2 != dd2) {
            cout << "You entered a wrong Dimensions!\n\n";
            cout << "Enter Dimensions of first Matrix:\n";
            cin >> d1 >> d2;
            cout << "Enter Dimensions of second Matrix:\n";
            cin >> dd1 >> dd2;
        }
    } else if ((d1 != dd2 or d2 != dd1) and (a == 3)) {
        while (d1 != dd2 or d2 != dd1) {
            cout << "You entered a wrong Dimensions!\n\n";
            cout << "Enter Dimensions of first Matrix:\n";
            cin >> d1 >> d2;
            cout << "Enter Dimensions of second Matrix:\n";
            cin >> dd1 >> dd2;
        }
    }
    Matrix<T> arr1(d1, d2), arr2(dd1, dd2);
    cout << "enter the first matrix" << '\n';
    cin >> arr1;
    cout << "enter the second matrix" << '\n';
    cin >> arr2;
    if (a == 1) {
        arr1 += arr2;
    } else if (a == 2) {
        arr1 -= arr2;
    } else if (a == 3) {
        arr1 *= arr2;
    } else {
        int aa;
        cout << "Which matrix need to Transpose (1 or 2)?\n";
        cin >> aa;
        if (aa == 1) {
            arr1.transpose();
            cout << arr1 << endl;
            swap(d1, d2);
            return;
        } else if (aa == 2) {
            arr2.transpose();
            cout << arr2 << endl;
            swap(dd1, dd2);
            return;
        }
    }
    cout << arr1 << endl;
}


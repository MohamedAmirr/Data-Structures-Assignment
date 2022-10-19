#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;
using namespace std;

//A binary search based function to find the position where item should be inserted  in array[low..high]
int binarySearch(int *array, int numbers, int low, int high) {
    int l = low - 1, r = high + 1, mid;
    while (r - l > 1) {// FFFTTT
        mid = l + (r - l) / 2;
        if (array[mid] >= numbers) {
            r = mid;
        } else l = mid;
    }
    return r;
}

//Function to sort an array[] of size 'n'
void binaryInsertionSort(int *array, int numOfArray) {
    int select, place;
    for (int i = 1; i < numOfArray; i++) {
        int j = i - 1;
        select = array[i];
        // find place where select should be insert
        place = binarySearch(array, select, 0, j);
        //Move all elements after place to create space
        while (j >= place) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = select;
    }
}

//function to sort an array using insertion sort
void insertionSort(int *array, int size) {
    int temp;
    for (int i = 1; i < size; i++) {
        temp = array[i];
        int j = i - 1;
        //Move elements of arr[0..i-1], that are  greater than temp, to one position ahead   of their current position
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

int main() {
    int *arr, n;
    string type;
    cout << "which  algorithm you want use?\n";
    cin >> type;
    // to generate random num
    auto RandomNum = []() -> int { return rand() % 10000; };
    cin >> n;
    arr = new int[n];
    //fill array with random num
    generate(arr, arr + n, RandomNum);
    /* complexity of binary insertion sort
     * best case     -> n log n
     * average case  -> o(n^2)
     * worst case    -> o(n^2)
     * */
    // if condition to choose algorithm which use
    if (type == "binaryInsertionSort") {
        //start time before function call
        auto start = high_resolution_clock::now();
        binaryInsertionSort(arr, n);
        //end time after function call
        auto stop = high_resolution_clock::now();
        //duration of run time
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << " " << "microsecond" << endl;
    }
        /* complexity of insertion sort
        * best case     -> o(n)
        * average case  -> o(n^2)
        * worst case    -> o(n^2)
        * */
    else {
        auto start = high_resolution_clock::now();
        insertionSort(arr, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << duration.count() << " " << "microsecond" << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class sorter {
public:
    sorter() {
    }

    friend class Testbed;

    virtual void sort(vector<int> &v, int size) {
    }
};

class SelectionSort : public sorter {
public:
    SelectionSort() : sorter() {
    }

    virtual void sort(vector<int> &v, int size) {
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (v[i] > v[j])
                    swap(v[i], v[j]);
            }
        }
    }
};

class QuickSort : public sorter {
public:
    QuickSort() : sorter() {
    }

    void sort(vector<int> &v, int size) {
        quicking_sort(v, 0, v.size() - 1);
    }

    virtual void quicking_sort(vector<int> &v, int left, int right) {
        int i = left, j = right;
        int temp;
        int pivot = v[(left + right) / 2];
        while (i <= j) {
            while (v[i] < pivot)
                i++;
            while (v[j] > pivot)
                j--;
            if (i <= j) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
                j--;
            }
        }
        if (left < j)
            quicking_sort(v, left, j);
        if (i < right)
            quicking_sort(v, i, right);
    }
};

class Testbed {
public:
    friend class sorter;

    vector<int> GenerateRandomList(int min, int max, int size) {
        vector<int> v(size);
        for (int i = 0; i < v.size(); ++i) {
            int random_num = (rand() * (int) (max - min) / RAND_MAX);
            v[i] = random_num;
        }
        return v;
    }

    vector<int> GenerateReverseOrderedList(int min, int max, int size) {
        vector<int> v(size);
        for (int i = 0; i < v.size(); ++i) {
            int random_num = (rand() * (int) (max - min) / RAND_MAX);
            v[i] = random_num;
        }
        std::sort(v.begin(), v.end(), greater<>());
        return v;
    }

    auto RunOnce(sorter *obj, vector<int> &v, int size) {
        auto start = high_resolution_clock::now();
        obj->sort(v, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        return duration.count();
    }

    long long RunAndAverage(sorter *obj, int type, int min, int max, int size, int sets_num) {
        long long sum = 0, average;
        if (type == 0) {
            for (int i = 0; i < sets_num; ++i) {
                vector<int> v = GenerateRandomList(min, max, size);
                auto start = high_resolution_clock::now();
                obj->sort(v, v.size());
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                sum += duration.count();
            }
        } else {
            for (int i = 0; i < sets_num; ++i) {
                vector<int> v = GenerateReverseOrderedList(min, max, size);
                auto start = high_resolution_clock::now();
                obj->sort(v, v.size());
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                sum += duration.count();
            }
        }
        average = (sum / sets_num);
        return average;
    }

    void RunExperient(sorter *obj, int type, int min, int max, int min_val, int max_val, int sets_num, int step) {
        if (type == 0) {
            cout << "set of size" << setw(18) << "average time" << '\n';
            for (int i = min_val, j = 0; i <= max_val; i += step, j++) {
                cout << "( " << i << " )" << setw(16);
                cout << RunAndAverage(obj, type, min, max, i, sets_num) << '\n';
            }
        } else if (type == 1) {
            cout << "set of size" << setw(18) << "average time" << '\n';
            for (int i = min_val; i <= max_val; i += step) {
                cout << "( " << i << " )" << setw(16);
                cout << RunAndAverage(obj, type, min, max, i, sets_num) << '\n';
            }
        }
    }
};

int main() {
    Testbed obj;
    sorter *obj2 = new SelectionSort,*obj3=new QuickSort;
    cout<<"Selection Sort with Random List:\n";
    obj.RunExperient(obj2, 0, 100, 100000, 100, 1000, 100, 100);
    cout<<"\nSelection Sort with reversed random List:\n\n";
    obj.RunExperient(obj2, 1, 100, 100000, 100, 1000, 100, 100);
    cout<<"\nQuick Sort with Random List:\n\n";
    obj.RunExperient(obj3, 0, 100, 100000, 100, 1000, 100, 100);
    cout<<"\nQuick Sort with reversed Random List:\n\n";
    obj.RunExperient(obj3, 1, 100, 100000, 100, 1000, 100, 100);

}
// Problem 2
#include <iostream>

using namespace std;

template<class Type>
class Queue {
private:
    template<class T>
    struct Node {
    public:
        T data;
        int idx = 0;
        Node<T> *next;

        Node() : next(nullptr) {}

        Node(const T &item, Node<T> *ptr = nullptr) :
                data(item), next(ptr) {}
    };

    Node<Type> *first;
    Node<Type> *last;
    bool check = 0;
    int len = 0;
    int idx = 0;


public:
    bool empty() {
        return (first == nullptr);
    }

    Queue() {
        first = nullptr;
        last = nullptr;
    }

    void push(Type value) {
        if (first == nullptr) {
            first = new Node<Type>(value);
            last = first;
            if (check == 0)
                first->idx = idx++;
            else first->idx = idx;
            last->next = nullptr;
        } else {
            last->next = new Node<Type>(value);
            if (check == 0)
                last->next->idx = idx++;
            else last->next->idx = idx;
            last = last->next;
            last->next = nullptr;
        }
        len++;
    }

    void pop() {
        Node<Type> *tmp = first;
        first = first->next;
        delete tmp;
        len--;
        if(len==0)idx=0;
    }

    Type front() {
        if (first->data == NULL) {
            cout << "8alat ya bashmohands";
            return -1;
        }
        return first->data;
    }

    int time(int k) {
        int tot = 0;
        check = 1;
        if (k < len)
            while (!empty()) {
                if (first->data > 0) {
                    first->data--;
                    tot++;
                }
                idx = first->idx;
                push(first->data);
                if (first->idx == k and first->data == 0) {
                    break;
                }
                pop();
            }
        else return -1;
        check = 0;
        return tot;
    }

    ~Queue() {
        Node<Type> *tmp = first;
        while (len--) {
            Node<Type> *nex = tmp->next;
            delete tmp;
            tmp = nex;
        }
    }

};

int main() {
    Queue<int> q;
    // Test case 1
    // [2, 3, 2] , k = 2;
    q.push(2);
    q.push(3);
    q.push(2);
    cout << "Output: " << q.time(2) << " Seconds.\n";
    while (!q.empty())q.pop(); //clear queue

    // Test Case 2
    // [5, 1, 1, 1], k = 0;
    q.push(5);
    q.push(1);
    q.push(1);
    q.push(1);
    cout << "Output: " << q.time(0) << " Seconds.\n";
    while (!q.empty())q.pop(); //clear queue

    // Test Case 3
    // [1, 2, 3, 4, 5], k = 3;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "Output: " << q.time(3) << " Seconds.\n";
    while (!q.empty())q.pop(); //clear queue

    // Test Case 4
    // [2, 4, 6, 8], k = 1;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    cout << "Output: " << q.time(1) << " Seconds.\n";
    while (!q.empty())q.pop(); //clear queue

}

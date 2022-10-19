#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack {
public:
    queue<int> qu;

    void push(int x) {
        int siz = qu.size();
        qu.push(x);
        while (siz--) {
            qu.push(qu.front());
            qu.pop();
        }
    }

    int top() {
        if (qu.empty()) {
            cout << "No element to top\n";
            return (-1);
        } else
            return (qu.front());
    }

    void pop() {
        if (qu.empty())
            cout << "No element to pop\n";
        else
            qu.pop();
    }

};

int main() {
    Stack s;
    string type;
    string flag;
    cout << "Enter yes to start or stop to exit:\n";
    cin >> flag;
    while (flag == "yes") {
        cout << "Enter what do you want to do:\n";
        cin >> type;
        if (type == "push") {
            int n;
            cout << "How many numbers you want to push:\n";
            cin >> n;
            cout << "Enter numbers:\n";
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                s.push(num);
            }
        } else if (type == "top") {
            cout << s.top() << endl;
        } else if (type == "pop") {
            s.pop();
        } else if (type == "stop") {
            return 0;
        }
    }
    return 0;
}

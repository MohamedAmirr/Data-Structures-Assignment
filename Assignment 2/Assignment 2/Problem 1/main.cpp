// Problem 1
#include <iostream>

using namespace std;

class stack {
private:

    struct Node {
    public:
        char data;
        Node *prev, *next;

        Node() : prev(nullptr) {}

        Node(const char &item) :
                data(item) {}
    };

    int len;
    Node *first;
    Node *last;

public:
    stack() {
        len = 0;
        first = nullptr;
        last = nullptr;
    }

    bool empty() {
        return len == 0;
    }

    void pop() {
        if (len == 0) {
            return;
        }
        Node *tmp = last;
        last = last->prev;
        delete tmp;
        len--;
    }

    void push(char value) {
        if (len == 0) {
            first = new Node(value);
            last = first;
            first->prev = new Node(NULL);
            first->prev = nullptr;
        } else {
            last->next = new Node(value);
            last->next->prev = last;
            last = last->next;
            first->prev = new Node(NULL);
        }
        len++;
    }

    char top() {
        if (!len) {
            cout << "There is no data in stack!";
        }
        return last->data;
    }

    // convert to the simplified canonical path
    void simplify(string path) {
        int cnt = 0;
        for (int i = path.size() - 1; i >= 0; --i) {
            if (i > 1 and path[i] == '.' and path[i - 1] == '.' and path[i - 2] == '.') {
                while (path[i] == '.') {
                    push(path[i]);
                    i--;
                }
                i++;
                continue;
            }
            if (path[i] == '.' and i > 0 and path[i - 1] == '.')
                cnt++;
            if (path[i] == '.' or (path[i] == '/' and (empty() or top() == '/')))
                continue;
            while (i > 0 and path[i] != '/' and cnt)
                i--;
            if (path[i] == '/' and cnt) {
                cnt--;
                continue;
            }
            push(path[i]);
        }
        if (empty())
            push('/');
    }

    void print() {
        while (!empty()) {
            cout << top();
            pop();
        }
    }

    ~stack() {
        Node *tmp = first;
        while (len--) {
            Node *nex = tmp->next;
            delete tmp;
            tmp = nex;
        }
    }
};

int main() {
    string path;

    //Test case1
    path = "/home/";
    stack s1;
    cout << "Input: \t" << path << endl;
    s1.simplify(path);
    cout << "Output: ";
    s1.print();
    cout << endl << endl;

    //Test case2
    path = "/../";
    stack s2;
    cout << "Input: \t" << path << endl;
    s2.simplify(path);
    cout << "Output: ";
    s2.print();
    cout << endl << endl;

    //Test case3
    path = "/home//foo/";
    stack s3;
    cout << "Input: \t" << path << endl;
    s3.simplify(path);
    cout << "Output: ";
    s3.print();
    cout << endl << endl;

    //Test case4
    path = "/a/./b/../../c/";
    stack s4;
    cout << "Input: \t" << path << endl;
    s4.simplify(path);
    cout << "Output: ";
    s4.print();
    cout << endl << endl;

    //Test case5
    path = "/a/..";
    stack s5;
    cout << "Input: \t" << path << endl;
    s5.simplify(path);
    cout << "Output: ";
    s5.print();
    cout << endl << endl;

    //Test case6
    path = "/../../../../../a";
    stack s6;
    cout << "Input: \t" << path << endl;
    s6.simplify(path);
    cout << "Output: ";
    s6.print();
    cout << endl << endl;

    //Test case7
    path = "/.../";
    stack s7;
    cout << "Input: \t" << path << endl;
    s7.simplify(path);
    cout << "Output: ";
    s7.print();
    cout << endl << endl;

    //Test case8
    path = "/a//b//c//////d";
    stack s8;
    cout << "Input: \t" << path << endl;
    s8.simplify(path);
    cout << "Output: ";
    s8.print();
    cout << endl;
}

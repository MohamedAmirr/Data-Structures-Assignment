#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

using namespace std;


template<class type>
class List {
private:
    template<class T>
    struct Node {
    public:
        T data;
        Node<T> *next, *prev;

        Node() : next(nullptr), prev(nullptr) {}

        Node(const T &item, Node<T> *ptr = nullptr) :
                data(item), next(ptr) {}
    };

    int len;
    Node<type> *first;
    Node<type> *last;
public:
    List() {
        len = 0;
        first = nullptr;
        last = nullptr;
    }

    class Iterator {
        friend class List;

    private:
        Node<type> *ptr;
    public:
        Iterator() : ptr(nullptr) {}

        bool operator!=(const Iterator &itr) const {
            return ptr != itr.ptr;
        }

        bool operator==(const Iterator &itr) const {
            return ptr == itr.ptr;
        }

        Iterator operator++(int) {
            if (ptr->next == NULL) {
                throw invalid_argument("Null Position!");
            }
            ptr = ptr->next;
            return *this;
        }

        Iterator operator--(int) {
            if (ptr->prev == NULL) {
                throw invalid_argument("Null Position!");
            }
            ptr = ptr->prev;
            return *this;
        }

        type operator*() const {
            return ptr->data;
        }
    };

    Iterator begin() const {
        Iterator obj;
        obj.ptr = first;
        return obj;
    }

    Iterator end() const {
        Iterator obj;
        obj.ptr = last->next;
        return obj;
    }


    List(type value, int initial_size) {
        for (int i = 0; i < initial_size; ++i) {
            if (i == 0) {
                first = new Node<type>(value);
                last = first;
                last->next = new Node<type>(NULL);
                last->next = nullptr;
                first->prev = new Node<type>(NULL);
                first->prev = nullptr;
                last->next->prev = last;
            } else {
                last->next = new Node<type>(value);
                last->next->prev = last;
                last = last->next;
                last->next = new Node<type>(NULL);
                last->next = nullptr;
                first->prev = new Node<type>(NULL);
                first->prev = nullptr;
                last->next->prev = last;
            }
            len++;
        }
    }

    void push_back(type T) {
        if (len == 0) {
            first = new Node<type>(T);
            last = first;
            last->next = new Node<type>(NULL);
            first->prev = new Node<type>(NULL);
            last->next->prev = last;
            first->prev = nullptr;
        } else {
            last->next = new Node<type>(T);
            last->next->prev = last;
            last = last->next;
            last->next = new Node<type>(NULL);
            first->prev = new Node<type>(NULL);
            last->next->prev = last;
        }
        len++;
    }

    size_t size() {
        return len;
    }

    void insert(type value, Iterator position) {
        if (position.ptr == last->next) {
            push_back(value);
            return;
        } else if (position.ptr == first) {
            Node<type> *newNode = new Node<type>(value);
            first->prev = newNode;
            first->prev->next = first;
            first = first->prev;
        } else {
            Node<type> *tmp = first;
            while (tmp->next != position.ptr) {
                tmp = tmp->next;
            }
            Node<type> *nextNode = position.ptr->next;
            Node<type> *prevNode = position.ptr->prev;
            Node<type> *val = new Node<type>(value);
            val->next = tmp->next;
            val->prev = tmp->prev;
            prevNode->next = val;
            tmp->prev = val;
            tmp->next = val;
        }
        len++;
    }

    Iterator erase(Iterator position) {
        if (position.ptr == first) {
            Node<type> *tmp = first;
            first->next->prev = nullptr;
            first = first->next;
            Iterator it;
            it.ptr = tmp->next;
            delete tmp;
            len--;
            return it;
        } else {
            Node<type> *currentNode = position.ptr;
            Node<type> *nextNode = position.ptr->next;
            Node<type> *prevNode = position.ptr->prev;
            Node<type> *tmp = first;

            while (tmp->next != currentNode) {
                tmp = tmp->next;
            }

            tmp->next = nextNode;
            tmp->prev = prevNode;
            Iterator it;
            it.ptr = nextNode;
            delete currentNode;
            len--;
            return it;
        }
    }

    List<type> &operator=(List<type> li) {
        List<type> newList;
        List<type>::Iterator it = newList.begin();
        List<type>::Iterator it1 = li.begin();
        while (it1->next != NULL) {
            it = it1;
            it1++;
            it++;
            it = new Node<type>;
        }
        it->next = NULL;
        return newList;
    }

    ~List() {
        Node<type> *tmp = first;
        while (len--) {
            Node<type> *nex = tmp->next;
            delete tmp;
            tmp = nex;
        }
    }
};

int main() {
    List<int> mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(3);
    cout << "After push numbers from 1 to 3:\n";
    List<int>::Iterator it = mylist.begin();
    while (it != mylist.end()) {
        cout << *(it) << ' ';
        it++;
    }
    cout << endl;
    it = mylist.begin();
    try {
        it++;
    }
    catch (invalid_argument &e) {
        cerr << e.what() << endl;
        return -1;
    }
    mylist.insert(9, it);
    it = mylist.begin();
    cout << "After insert 9 in second position:\n";
    while (it != mylist.end()) {
        cout << *(it) << ' ';
        it++;
    }
    cout << endl;
    mylist.push_back(4);
    mylist.push_back(5);
    it = mylist.begin();
    it++;
    it = mylist.erase(it);
    it--;
    cout << "After push back numbers from 4 to 5 and erase second position:\n";
    while (it != mylist.end()) {
        cout << *(it) << ' ';
        it++;
    }
    cout << endl;

    try {
        it++;
    }
        //access wrong position
    catch (invalid_argument &e) {
        cerr << e.what() << endl;
        return -1;
    }
    return 0;
}

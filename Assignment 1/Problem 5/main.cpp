#include <iostream>
#include <vector>

using namespace std;

class StudentName {
private:
    string Name;
    vector<string> final;
public:
    StudentName(string fullName) {
        int spaces = 0, position = 0;
        string lastName;

        for (int i = 0; i < fullName.size(); ++i) {
            if (fullName[i] == ' ') {
                spaces++;
                position = i;
            }
        }

        if (spaces == 0) {
            Name = fullName + " " + fullName + " " + fullName;
        } else if (spaces == 1) {
            lastName = fullName.substr(position);
            Name = fullName + lastName;
        } else {
            Name = fullName;
        }
    }

    string getName() {
        return Name;
    }

    void storeName() {
        string name = "";
        for (int i = 0; i < Name.size(); ++i) {
            if (Name[i] == ' ') {
                final.push_back(name);
                name = "";
            } else if (i == Name.size() - 1) {
                name += Name[i];
                final.push_back(name);
            } else {
                name += Name[i];
            }
        }
    }

    void print() {
        storeName();
        cout << "Detailed parts of the name:\n";
        for (int i = 0; i < final.size(); ++i) {
            cout << i + 1 << ") " << final[i] << endl;
        }
    }

    bool replace(int i, int j) {
        if (i > final.size() || j > final.size() || j < 0 || i < 0) {
            cout << "Error, Out of range.\n";
            return false;
        } else {
            swap(final[j - 1], final[i - 1]);
            cout << "Name after replacement: ";
            for (int k = 0; k < final.size(); ++k) {
                cout << final[k] << " ";
            }
            cout << endl;
            return true;
        }
    }
};

int main() {
//    string name ;
//    getline(cin, name);
//    StudentName S1(name);
//    S1.print();
//    S1.replace(1,3);

    string name;
    // Test case1
    name = "ahmed Mohamed sayed";
    StudentName test1(name);
    cout << "Test Case 1:\n";
    test1.print();
    cout << "Name before replace: " << test1.getName() << endl;
    test1.replace(1, 3);

    // Test Case2
    name = "sara Mohamed";
    StudentName test2(name);
    cout << "\nTest Case 2:\n";
    test2.print();
    cout << "Name before replace: " << test2.getName() << endl;
    test2.replace(1, 2);

    // Test Case3
    name = "khaled";
    StudentName test3(name);
    cout << "\nTest Case 3:\n";
    test3.print();
    cout << "Name before replace: " << test3.getName() << endl;
    test3.replace(-1, 1);

    // Test Case4
    name = "aya ali ahmed sayed";
    StudentName test4(name);
    cout << "\nTest Case 4:\n";
    test4.print();
    cout << "Name before replace: " << test4.getName() << endl;
    test4.replace(2, 4);

    // Test Case5
    name = "ahmed hassan ali";
    StudentName test5(name);
    cout << "\nTest Case 5:\n";
    test5.print();
    cout << "Name before replace: " << test5.getName() << endl;
    test5.replace(1, 2);
    test5.replace(3, 1);
    test5.replace(2, 4);

    return 0;
}

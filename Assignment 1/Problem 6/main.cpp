#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

//Class to entry information to Phone Directory
class PhoneDirectory {
private:
    string first_name, last_name, phone_num;
public:
    // constructor to take first name & last name & phone number
    PhoneDirectory(string fn, string ln, string pn) {
        first_name = fn;
        last_name = ln;
        phone_num = pn;
    }

    // function to return first name
    string getFirst_name() {
        return first_name;
    }

    // function to return last name
    string getLast_name() {
        return last_name;
    }

    // function to return phone number
    string getPhone_num() {
        return phone_num;
    }


};

void BubbleSort(vector<PhoneDirectory> &my_info) {
    for (int i = 0; i < my_info.size(); i++) {
        for (int j = i + 1; j < my_info.size(); j++) {
            if (my_info[i].getFirst_name() > my_info[j].getFirst_name()) {
                swap(my_info[i], my_info[j]);
            }
        }
    }
}

void merge(vector<PhoneDirectory> &my_info, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<PhoneDirectory> first, second;

    for (int i = 0; i < n1; ++i)first.push_back(my_info[i]) ;
    for (int i = 0; i < n2; ++i)second.push_back(my_info[mid + 1 + i]);

    int index1 = 0, index2 = 0, mergedIndex = l;
    while (index1 < n1 and index2 < n2) {
        if (first[index1].getFirst_name() <= second[index2].getFirst_name()) {
            my_info[mergedIndex] = first[index1];
            index1++;
        } else {
            my_info[mergedIndex] = second[index2];
            index2++;
        }
        mergedIndex++;
    }
    while (index1 < n1) {
        my_info[mergedIndex] = first[index1];
        mergedIndex++;
        index1++;
    }
    while (index2 < n2) {
        my_info[mergedIndex] = second[index2];
        mergedIndex++;
        index2++;
    }

}

void mergeSort(vector<PhoneDirectory> &my_info, int l, int r) {
    if (l >= r)return;

    int mid = l + (r - l) / 2;
    mergeSort(my_info, l, mid);
    mergeSort(my_info, mid + 1, r);
    merge(my_info, l, mid, r);
}

int binarySearch(vector<PhoneDirectory> &my_info, string firstName) {
    int l = -1, r = my_info.size(), mid;
    while (r - l > 1) {
        mid = l + (r - l) / 2;
        if (my_info[mid].getFirst_name() >= firstName) {
            r = mid;
        } else l = mid;
    }
    return r;
}

void insertionSort(vector<PhoneDirectory>&my_info){
    for (int i = 1; i < my_info.size(); ++i) {
        PhoneDirectory key=my_info[i];
        int j=i-1;

        while(j>=0 and my_info[j].getFirst_name()>key.getFirst_name()){
            my_info[j+1]=my_info[j];
            j--;
        }
        my_info[j+1]=key;
    }
}


int main() {
    // vector of object to store all information
    vector<PhoneDirectory> my_info;
    string choose;
    cout << "Hello, please enter yes to show  menu\n";
    cin >> choose;
    // while loop to show menu if user enter yes
    while (choose == "yes") {
        cout << "1. Add an entry to the directory\n"
                "2. Look up a phone number\n"
                "3. Look up by first name\n"
                "4. Delete an entry from the directory\n"
                "5. List All entries in phone directory\n"
                "6. Exit form this program\n";
        char option;
        cout << "please choose number from 1 : 6 to access to the directory\n";
        cin >> option;
        // if condition to add if the user choose number 1
        if (option == '1') {
            int numOfAdd;
            cout << "How many entry do you want to add:\n";
            cin >> numOfAdd;
            // for loop to push in vector all information
            for (int i = 0; i < numOfAdd; i++) {
                // fn -> first name , ln -> last name , pn -> phone number
                string fn, ln, pn;
                cin.ignore();
                cout << "please enter your first name :\n";
                getline(cin, fn);
                cout << "please enter your last name :\n";
                getline(cin, ln);
                cout << "please enter your phone number:\n";
                cin >> pn;
                PhoneDirectory entry(fn, ln, pn);
                my_info.push_back(entry);
            }
            cout << "All information has been added successfully\n";
        }
            //if condition to look up an entry by phone number if the user choose number 2
        else if (option == '2') {
            // check to quit from for loop if the phone number not exist
            bool check = false;
            string pn;
            cout << "Please enter phone number:\n";
            cin >> pn;
            // for loop to search in vector
            for (int i = 0; i < my_info.size(); i++) {
                // if condition to check if the phone number exists
                if (pn == my_info[i].getPhone_num()) {
                    cout << "Look up an entry by Phone number\n";
                    cout << "First Name: " << my_info[i].getFirst_name() << endl
                         << "Last Name: " << my_info[i].getLast_name() << endl
                         << "Phone Number: " << my_info[i].getPhone_num() << endl;
                    check = true;
                }
            }
            // in case phone number not exists
            if (check == false) {
                cout << "Not Found :(\n";
            }
        }
            // if condition to look up an entry by first name if the user choose number 3
        else if (option == '3') {
            string fn;
            // check to quit from for loop if the first name not exist
            bool check = false;
            mergeSort(my_info, 0, (int)my_info.size()-1);
            cout << "Please enter first name:\n";
            cin >> fn;
            int ans = binarySearch(my_info, fn);
            if (ans != my_info.size()) {
                cout << "Look up an entry by first name\n";
                cout << "First Name: " << my_info[ans].getFirst_name() << endl
                     << "Last Name: " << my_info[ans].getLast_name() << endl
                     << "Phone Number: " << my_info[ans].getPhone_num() << endl;
                check = true;
            }
            // in case first name not exists
            if (check == false) {
                cout << "Not Found :(\n";
            }
        }
            // if condition to Delete  an entry by first name if the user choose number 4
        else if (option == '4') {
            string fn;
            cout << "Please enter your first name:\n";
            cin >> fn;
            bool found=0;
            // for loop to search in vector
            for (int i = 0; i < my_info.size(); i++) {
                // if condition to check if the first name exists
                if (fn == my_info[i].getFirst_name()) {
                    my_info.erase(my_info.begin() + i);
                    cout << "All information about this name has been deleted successfully\n";
                    found=1;
                    break;
                }
                    // in case first name not exists
            }
            if(!found){
                cout << "Not Found :(\n";
                break;
            }
        }
            // if condition to list an entry by first name if the user choose number 5
        else if (option == '5') {
            BubbleSort(my_info);
            for (int i = 0; i < my_info.size(); i++) {
                cout << i + 1 << "'s Contact:\n";
                cout << "First Name: " << my_info[i].getFirst_name() << endl
                     << "Last Name: " << my_info[i].getLast_name() << endl
                     << "Phone Number: " << my_info[i].getPhone_num() << endl << endl;
            }
        }
            // if condition to quit the program if the user choose number 4
        else if (option == '6') {
            cout << "thank you :)\n";
            break;
        }
    }
    return 0;
}
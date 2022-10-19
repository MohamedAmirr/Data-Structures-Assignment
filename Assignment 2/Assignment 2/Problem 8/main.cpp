#include <iostream>

using namespace std;

void printPostOrder(string preorder, string inOrder, int strt, int end, int &currIndx) {
    if (strt > end)return;

    int root = strt;
    for (int i = strt; i < end; ++i) {
        if (preorder[currIndx] == inOrder[i]) {
            root = i;
            break;
        }
    }
    currIndx++;

    printPostOrder(preorder, inOrder, strt, root - 1, currIndx);
    printPostOrder(preorder, inOrder, root + 1, end, currIndx);
    cout << inOrder[root];
}

int main() {
    int currIndex = 0;
    cout << "Post order of (ABFGC, FBGAC): ";
    printPostOrder("ABFGC", "FBGAC", 0, 4, currIndex);
    currIndex = 0;
    cout << endl;
    cout << endl;
    cout << "Post order of (KHUGZ, UHGKZ): ";
    printPostOrder("KHUGZ", "UHGKZ", 0, 4, currIndex);
    currIndex = 0;
    cout << endl;
    cout << endl;
    cout << "Post order of (UZAYPGM, AZYUGPM): ";
    printPostOrder("UZAYPGM", "AZYUGPM", 0, 6, currIndex);
    currIndex = 0;
    cout << endl;
    cout << endl;
    cout << "Post order of (ZMARPEFNYI, RAEPFMNZYI): ";
    printPostOrder("ZMARPEFNYI", "RAEPFMNZYI", 0, 9, currIndex);
    currIndex = 0;
    cout << endl;
    cout << endl;
    cout << "Post order of (ZMARPEFNQYI, RAEPFMNQZYI): ";
    printPostOrder("ZMARPEFNQYI", "RAEPFMNQZYI", 0, 10, currIndex);
    return 0;
}

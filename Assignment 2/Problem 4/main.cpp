#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return isSymmetric(root, root);
    }

    bool isSymmetric(TreeNode *first, TreeNode *second) {
        if (first == nullptr && second == nullptr)
            return true;
        if (first != nullptr && second != nullptr && first->val == second->val)
            return isSymmetric(first->left, second->right) && isSymmetric(first->right, second->left);
        return false;
    }
};

int main() {

    cout << "test case 1: " << endl << "Input: root = [1,2,2,3,4,4,3]" << endl;
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);
    Solution s;
    if (s.isSymmetric(root1)) {
        cout << "Output: true";
    } else
        cout << "Output: false";
    cout << endl << endl;

    cout << "test case 2: " << endl << "Input: root = [1,2,2,null,3,null,3] " << endl;
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = nullptr;
    root2->left->right = new TreeNode(3);
    root2->right->left = nullptr;
    root2->right->right = new TreeNode(3);
    Solution ss;
    if (ss.isSymmetric(root2)) {
        cout << "Output: true";
    } else
        cout << "Output: false";
    cout<<endl;
    cout<<endl;

    cout << "test case 3: " << endl << "Input: root = [1,2,2,5,3,2,3] " << endl;
    TreeNode *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(2);
    root3->left->left = new TreeNode(5);
    root3->left->right = new TreeNode(3);
    root3->right->left = new TreeNode(2);
    root3->right->right = new TreeNode(3);
    Solution sol;
    if (sol.isSymmetric(root3)) {
        cout << "Output: true";
    } else
        cout << "Output: false";
    cout<<endl;
    cout<<endl;

    cout << "test case 4: " << endl << "Input: root = [1,2,2,3,3,2,2] " << endl;
    TreeNode *root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(2);
    root4->left->left = new TreeNode(3);
    root4->right->right = new TreeNode(3);
    root4->left->right = new TreeNode(2);
    root4->right->left = new TreeNode(2);
    Solution sol1;
    if (sol1.isSymmetric(root4)) {
        cout << "Output: true";
    } else
        cout << "Output: false";
    cout<<endl;
    cout<<endl;

    cout << "test case 5: " << endl << "Input: root = [1,2,2,5,5,9,9,3,3] " << endl;
    TreeNode *root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(2);
    root5->left->left = new TreeNode(5);
    root5->right->right = new TreeNode(5);
    root5->left->left->left = new TreeNode(9);
    root5->right->right->right = new TreeNode(9);
    root5->left->right = new TreeNode(3);
    root5->right->left = new TreeNode(3);
    Solution sol2;
    if (sol2.isSymmetric(root5)) {
        cout << "Output: true";
    } else
        cout << "Output: false";


    return 0;
}
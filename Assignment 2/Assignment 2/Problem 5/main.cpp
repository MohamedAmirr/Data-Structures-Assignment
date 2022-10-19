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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p != nullptr && q != nullptr && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};

int main() {
    cout << "test case 1:" << endl << "Input: p = [1,2,3], q = [1,2,3]" << endl;
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(1);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);
    b->left = new TreeNode(2);
    b->right = new TreeNode(3);
    Solution s;
    if (s.isSameTree(a, b))
        cout << "Output: true";
    else
        cout << "Output: false";
    cout << endl << endl;

    cout << "test case 2:" << endl << "Input: p = [1,2], q = [1,null,2]" << endl;
    TreeNode *aa = new TreeNode(1);
    TreeNode *bb = new TreeNode(1);
    aa->left = new TreeNode(2);
    bb->left = nullptr;
    bb->right = new TreeNode(2);
    Solution ss;
    if (ss.isSameTree(aa, bb))
        cout << "Output: true";
    else
        cout << "Output: false";
    cout << endl << endl;

    cout << "test case 3:" << endl << "Input: p = [1,2,1], q = [1,1,2]" << endl;
    TreeNode *aaa = new TreeNode(1);
    TreeNode *bbb = new TreeNode(1);
    aaa->left = new TreeNode(2);
    aaa->right = new TreeNode(1);
    bbb->left = new TreeNode(1);
    bbb->right = new TreeNode(2);
    Solution sss;
    if (sss.isSameTree(aaa, bbb))
        cout << "Output: true";
    else
        cout << "Output: false";

    cout << "test case 4:" << endl << "Input: p = [9,0,1,1,1,2], q = [9,0,1,1,1,2]" << endl;
    TreeNode *tree44 = new TreeNode(9);
    TreeNode *tree45 = new TreeNode(9);
    tree44->left = new TreeNode(0);
    tree44->left->left = new TreeNode(1);
    tree44->left = new TreeNode(1);
    tree44->right = new TreeNode(1);
    tree44->right->right = new TreeNode(2);
    tree45->left = new TreeNode(0);
    tree45->left->left = new TreeNode(1);
    tree45->left = new TreeNode(1);
    tree45->right = new TreeNode(1);
    tree45->right->right = new TreeNode(2);
    Solution sol;
    if (sol.isSameTree(tree44, tree45))
        cout << "Output: true";
    else
        cout << "Output: false";

    cout << "test case 5:" << endl << "Input: p = [], q = []" << endl;
    TreeNode *tree54 = new TreeNode;
    TreeNode *tree55 = new TreeNode;
    Solution sol1;
    if (sol1.isSameTree(tree54, tree55))
        cout << "Output: true";
    else
        cout << "Output: false";

    return 0;
}
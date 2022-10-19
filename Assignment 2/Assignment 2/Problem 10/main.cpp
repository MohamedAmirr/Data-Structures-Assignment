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

int SmallestElementSumrecersive(TreeNode *root, int k, int &counter) {
    if (root == nullptr)
        return 0;
    if (counter > k)
        return 0;
    int result = SmallestElementSumrecersive(root->left, k, counter);
    if (counter >= k)
        return result;
    result += root->val;
    counter++;
    if (counter >= k)
        return result;
    return result + SmallestElementSumrecersive(root->right, k, counter);
}

int SmallestElementsum(TreeNode *root, int k) {
    int c = 0;
    return SmallestElementSumrecersive(root, k, c);
}

int main() {
    //test case 1 :
    TreeNode *a = new TreeNode(54);
    a->left = new TreeNode(51);
    a->right = new TreeNode(75);
    a->left->left = new TreeNode(49);
    a->left->right = new TreeNode(52);
    a->right->left = new TreeNode(74);
    a->right->right = new TreeNode(85);
    int k = 1;
    cout << "sum here until the " << k << " smallest element in the tree is " << SmallestElementsum(a, k) << endl;

    //test case 2 :
    TreeNode *aa = new TreeNode(54);
    aa->left = new TreeNode(51);
    aa->right = new TreeNode(75);
    aa->left->left = new TreeNode(49);
    aa->left->right = new TreeNode(52);
    aa->right->left = new TreeNode(74);
    aa->right->right = new TreeNode(85);
    int k2 = 2;
    cout << "sum here until the " << k2 << " smallest element in the tree is " << SmallestElementsum(aa, k2) << endl;

    //test case 3 :
    TreeNode *b = new TreeNode(54);
    b->left = new TreeNode(51);
    b->right = new TreeNode(75);
    b->left->left = new TreeNode(49);
    b->left->right = new TreeNode(52);
    b->right->left = new TreeNode(74);
    b->right->right = new TreeNode(85);
    int k3 = 3;
    cout << "sum here until the " << k3 << " smallest element in the tree is " << SmallestElementsum(b, k3) << endl;

    //test case 4 :
    TreeNode *bb = new TreeNode(54);
    bb->left = new TreeNode(51);
    bb->right = new TreeNode(75);
    bb->left->left = new TreeNode(49);
    bb->left->right = new TreeNode(52);
    bb->right->left = new TreeNode(74);
    bb->right->right = new TreeNode(85);
    int k4 = 4;
    cout << "sum here until the " << k4 << " smallest element in the tree is " << SmallestElementsum(bb, k4) << endl;

    //test case 5 :
    TreeNode *c = new TreeNode(54);
    c->left = new TreeNode(51);
    c->right = new TreeNode(75);
    c->left->left = new TreeNode(49);
    c->left->right = new TreeNode(52);
    c->right->left = new TreeNode(74);
    c->right->right = new TreeNode(85);
    int k5 = 5;
    cout << "sum here until the " << k5 << " smallest element in the tree is " << SmallestElementsum(c, k5) << endl;
    return 0;
}
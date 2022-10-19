#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct tree_node {
public:
    int value;
    tree_node *left = NULL;
    tree_node *right = NULL;

    tree_node(int val) {
        value = val;
    }
};

//function to check if subtree left mirror to subtree right
void Mirror_image(tree_node *Node) {
    //if condition to check if tree is empty
    if (Node == NULL) {
        return;
    }
        //else check if subtree left mirror to subtree right
    else {
        tree_node *temp;
        Mirror_image(Node->left);
        Mirror_image(Node->right);
        temp = Node->left;
        Node->left = Node->right;
        Node->right = temp;
    }
}

//bool function to return true if the tree is empty or subtree a and b are the same, return false in any case other
bool same(tree_node *a, tree_node *b) {
    if (a == NULL && b == NULL) {
        return true;
    } else if (a != NULL && b != NULL && same(a->left, b->left) && same(a->right, b->right)) {
        return true;
    } else {
        return false;
    }
}

//bool function to check if the binary tree foldable or not
bool foldable(tree_node *root) {
    // result is boolean variable to save if the binary tree is foldable or not
    bool result;
    if (root == NULL) {
        return true;
    } else {
        Mirror_image(root->left);
        result = same(root->left, root->right);
        Mirror_image(root->left);
        return result;
    }
}

int main() {
    cout << "Test case 1:\n";
    tree_node *a = new tree_node(1);
    a->left = new tree_node(4);
    a->left->right = new tree_node(5);
    a->right = new tree_node(2);
    a->right->left = new tree_node(3);
    if (foldable(a) == 1) {
        cout << "True, binary tree is foldable\n";
    } else {
        cout << "False, binary tree is not foldable\n";
    }
    cout << "-------------------------------------------------------------------------------\n";
    cout << "Test case 2:\n";
    tree_node *a1 = new tree_node(1);
    a1->left = new tree_node(2);
    a1->left->right = new tree_node(6);
    a1->left->left = new tree_node(4);
    a1->right = new tree_node(3);
    a1->right->right = new tree_node(5);
    if (foldable(a1) == 1) {
        cout << "True, binary tree is foldable\n";
    } else {
        cout << "False, binary tree is not foldable\n";
    }
    cout << "-------------------------------------------------------------------------------\n";
    cout << "Test case 3:\n";
    tree_node *a2 = new tree_node(1);
    a2->left = new tree_node(2);
    a2->left->left = new tree_node(4);
    a2->right = new tree_node(3);
    a2->right->right = new tree_node(5);
    if (foldable(a2) == 1) {
        cout << "True, binary tree is foldable\n";
    } else {
        cout << "False, binary tree is not foldable\n";
    }
    cout << "-------------------------------------------------------------------------------\n";
    cout << "Test case 4:\n";
    tree_node *a3 = new tree_node(1);
    a3->left = new tree_node(2);
    a3->left->left = new tree_node(4);
    a3->left->right = new tree_node(6);
    a3->right = new tree_node(3);
    a3->right->right = new tree_node(5);
    a3->right->left = new tree_node(7);
    if (foldable(a3) == 1) {
        cout << "True, binary tree is foldable\n";
    } else {
        cout << "False, binary tree is not foldable\n";
    }
    cout << "-------------------------------------------------------------------------------\n";
    cout << "Test case 5:\n";
    tree_node *a4 = new tree_node(1);
    a4->left = new tree_node(2);
    a4->left->left = new tree_node(4);
    a4->left->right = new tree_node(6);
    a4->left->left->right = new tree_node(8);
    a4->right = new tree_node(3);
    a4->right->right = new tree_node(5);
    a4->right->left = new tree_node(7);
    a4->right->right->right = new tree_node(9);
    if (foldable(a4) == 1) {
        cout << "True, binary tree is foldable\n";
    } else {
        cout << "False, binary tree is not foldable\n";
    }

    return 0;
}

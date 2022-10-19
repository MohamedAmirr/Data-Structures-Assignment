#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Expression_tree {
public:
    string expression;
    Expression_tree *left = NULL;
    Expression_tree *right = NULL;

    Expression_tree(string expre) {
        expression = expre;
    }
};

// function to return the integer value  of a given string
int changeToInt(string expre) {
    int num = 0;
    //if condition to know if the number is negative or not,If it is not negative,change the number normally
    if (expre[0] != '-') {
        for (int i = 0; i < expre.length(); i++) {
            num = num * 10 + (int(expre[i]) - 48);
        }
    }
        //If it is negative, calculate the positive number ,first ignoring the sign and invert the sign at the end
    else {
        for (int i = 1; i < expre.length(); i++) {
            num = num * 10 + (int(expre[i]) - 48);
        }
        num = num * -1;
    }
    return num;
}

//function receives a node of tree and recursively evaluates it
int evalation(Expression_tree *root) {
    //if condition to change node of tree from string to int
    if (!root->left && !root->right) {
        return changeToInt(root->expression);
    }
    //calculate left subtree
    int left_node;
    left_node = evalation(root->left);
    //calculate right subtree
    int right_node;
    right_node = evalation(root->right);
    //if condition to choose operator to apply
    if (root->expression == "+") {
        return (left_node + right_node);
    }
    if (root->expression == "-") {
        return (left_node - right_node);
    }
    if (root->expression == "*") {
        return (left_node * right_node);
    }
    if (root->expression == "/") {
        return (left_node / right_node);
    }
}

int main() {
    cout << "Test case 1\n";
    cout << "Expression: + 3 * 4 / 8 2\n";
    Expression_tree *root = new Expression_tree("+");
    root->left = new Expression_tree("3");
    root->right = new Expression_tree("*");
    root->right->left = new Expression_tree("4");
    root->right->right = new Expression_tree("/");
    root->right->right->left = new Expression_tree("8");
    root->right->right->right = new Expression_tree("2");
    cout << evalation(root) << endl;
    cout << "--------------------------------------------------------------\n";
    cout << "Test case 2\n";
    cout << "Expression: * 5 + 10 * 2 / 5 5\n";
    Expression_tree *root1 = new Expression_tree("*");
    root1->left = new Expression_tree("5");
    root1->right = new Expression_tree("+");
    root1->right->left = new Expression_tree("10");
    root1->right->right = new Expression_tree("*");
    root1->right->right->left = new Expression_tree("2");
    root1->right->right->right = new Expression_tree("/");
    root1->right->right->right->left = new Expression_tree("5");
    root1->right->right->right->right = new Expression_tree("5");
    cout << evalation(root1) << endl;
    cout << "--------------------------------------------------------------\n";
    cout << "Test case 3\n";
    cout << "Expression: / 500 + 50 * 10 + 15 5\n";
    Expression_tree *root2 = new Expression_tree("/");
    root2->left = new Expression_tree("500");
    root2->right = new Expression_tree("+");
    root2->right->left = new Expression_tree("50");
    root2->right->right = new Expression_tree("*");
    root2->right->right->left = new Expression_tree("10");
    root2->right->right->right = new Expression_tree("+");
    root2->right->right->right->left = new Expression_tree("15");
    root2->right->right->right->right = new Expression_tree("5");
    cout << evalation(root2) << endl;
    cout << "--------------------------------------------------------------\n";
    cout << "Test case 4\n";
    cout << "Expression: - 20 * 6 + 10 / 30 3\n";
    Expression_tree *root3 = new Expression_tree("-");
    root3->left = new Expression_tree("20");
    root3->right = new Expression_tree("*");
    root3->right->left = new Expression_tree("6");
    root3->right->right = new Expression_tree("+");
    root3->right->right->left = new Expression_tree("10");
    root3->right->right->right = new Expression_tree("/");
    root3->right->right->right->left = new Expression_tree("30");
    root3->right->right->right->right = new Expression_tree("3");
    cout << evalation(root3) << endl;
    cout << "--------------------------------------------------------------\n";
    cout << "Test case 5\n";
    cout << "Expression: - 100 + 60 - 5 * 10 5\n";
    Expression_tree *root4 = new Expression_tree("-");
    root4->left = new Expression_tree("100");
    root4->right = new Expression_tree("+");
    root4->right->left = new Expression_tree("60");
    root4->right->right = new Expression_tree("-");
    root4->right->right->left = new Expression_tree("5");
    root4->right->right->right = new Expression_tree("*");
    root4->right->right->right->left = new Expression_tree("10");
    root4->right->right->right->right = new Expression_tree("5");
    cout << evalation(root4) << endl;
    return 0;
}
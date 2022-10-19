#include <bits/stdc++.h>


using namespace std;

template<class type>
class BSTNode {
public:
    type item;
    BSTNode *left, *right;

    BSTNode(type val) {
        item = val;
        left = right = NULL;
    }

    bool isEqual(BSTNode<type> *n1, BSTNode<type> *n2) {
        bool check1 = 1;
        bool check2 = 1;
        if (n1->left != NULL and n2->left != NULL and n2->left->item != n1->left->item)check1 = 0;
        if (n1->right != NULL and n2->right != NULL and n2->right->item != n1->right->item)check2 = 0;
        return n1->item == n2->item and check1 and check2;
    }

    bool isSubTree(BSTNode<type> *node1, BSTNode<type> *node2) {
        if (node1 == NULL and node2 == NULL)return 1;
        if (node1 == NULL or node2 == NULL)return 0;
        if (isEqual(node1, node2)) {
            return isSubTree(node1->left, node2->left) and isSubTree(node1->right, node2->right);
        } else {
            return isSubTree(node1->left, node2) or isSubTree(node1->right, node2);
        }
    }
};

template<class T>
class BSTFCI {
    BSTNode<T> *root;
public:
    BSTFCI() {
        root = NULL;
    }

    void add(T val, BSTNode<T> *node) {
        if (root == NULL) {
            root = new BSTNode<int>(val);
            root->left = NULL;
            root->right = NULL;
        } else if (node->item >= val) {
            if (node->left == NULL)
                node->left = new BSTNode<T>(val);
            else
                add(val, node->left);
        } else {
            if (node->right == NULL)
                node->right = new BSTNode<T>(val);
            else
                add(val, node->right);
        }
    }

    int getHeight(BSTNode<T> *node) {
        return node == NULL ? 0 : 1 + max(getHeight(node->left), getHeight(node->right));
    }

    bool isBalanced(BSTNode<T> *node) {
        if (node == NULL)return 1;

        int lh = getHeight(node->left);
        int rh = getHeight(node->right);

        return abs(lh - rh) <= 1 and isBalanced(node->left) and isBalanced(node->right);
    }

    bool isSubTree(BSTFCI<T> *firstTree, BSTFCI<T> *secondTree) {
        return firstTree->getRoot()->isSubTree(firstTree->root, secondTree->root);
    }

    void printRange(int l, int r, BSTNode<T> *node, bool &f) {
        if (node->left != NULL and node->left->item >= l)printRange(l, r, node->left, f);
        if (node->item >= l and node->item <= r) {
            if (f)cout << ',';
            cout << node->item, f = 1;
        }
        if (node->right != NULL)printRange(l, r, node->right, f);
    }

    BSTNode<T> *getRoot() {
        return root;
    }

    void destroy(BSTNode<T>*node){
        if(node!= nullptr){
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    ~BSTFCI(){
        destroy(root);
    }

};

void testCases1() {
    vector<BSTFCI<int> *> testCases(5);
    for (int i = 0; i < 5; ++i) {
        testCases[i] = new BSTFCI<int>;
    }
    //test case 1 for isBalanced function
    testCases[0]->add(1, testCases[0]->getRoot());
    testCases[0]->add(2, testCases[0]->getRoot());
    testCases[0]->add(3, testCases[0]->getRoot());
    cout << "Range from (2,5): ";
    cout << '[';
    bool f = 0;
    testCases[0]->printRange(2, 5, testCases[0]->getRoot(), f);
    cout << "]\n";
    int balance = testCases[0]->isBalanced(testCases[0]->getRoot());
    balance ? cout << "Tree is balanced\n" : cout << "Tree is not balanced\n";

    //test case 2 for isBalanced function
    testCases[1]->add(3, testCases[1]->getRoot());
    testCases[1]->add(2, testCases[1]->getRoot());
    testCases[1]->add(4, testCases[1]->getRoot());
    cout << "Range from (2,5): ";
    cout << '[';
    f = 0;
    testCases[1]->printRange(2, 5, testCases[1]->getRoot(), f);
    cout << "]\n";
    balance = testCases[1]->isBalanced(testCases[1]->getRoot());
    balance ? cout << "Tree is balanced\n" : cout << "Tree is not balanced\n";

    //test case 3 for isBalanced function
    testCases[2]->add(2, testCases[2]->getRoot());
    testCases[2]->add(1, testCases[2]->getRoot());
    testCases[2]->add(4, testCases[2]->getRoot());
    testCases[2]->add(3, testCases[2]->getRoot());
    cout << "Range from (1,1): ";
    cout << '[';
    f = 0;
    testCases[2]->printRange(1, 1, testCases[2]->getRoot(), f);
    cout << "]\n";
    balance = testCases[2]->isBalanced(testCases[2]->getRoot());
    balance ? cout << "Tree is balanced\n" : cout << "Tree is not balanced\n";

    //test case 4 for isBalanced function
    testCases[3]->add(3, testCases[3]->getRoot());
    testCases[3]->add(2, testCases[3]->getRoot());
    testCases[3]->add(4, testCases[3]->getRoot());
    testCases[3]->add(5, testCases[3]->getRoot());
    testCases[3]->add(1, testCases[3]->getRoot());
    cout << "Range from (6,6): ";
    cout << '[';
    f = 0;
    testCases[3]->printRange(6, 6, testCases[3]->getRoot(), f);
    cout << "]\n";
    balance = testCases[3]->isBalanced(testCases[3]->getRoot());
    balance ? cout << "Tree is balanced\n" : cout << "Tree is not balanced\n";

    //test case 5 for isBalanced function
    testCases[4]->add(1, testCases[4]->getRoot());
    testCases[4]->add(1, testCases[4]->getRoot());
    testCases[4]->add(1, testCases[4]->getRoot());
    testCases[4]->add(1, testCases[4]->getRoot());
    testCases[4]->add(2, testCases[4]->getRoot());
    testCases[4]->add(3, testCases[4]->getRoot());
    cout << "Range from (1,3): ";
    cout << '[';
    f = 0;
    testCases[4]->printRange(1, 3, testCases[4]->getRoot(), f);
    cout << "]\n";
    balance = testCases[4]->isBalanced(testCases[4]->getRoot());
    balance ? cout << "Tree is balanced\n" : cout << "Tree is not balanced\n";
}

void testCases2() {
    vector<BSTFCI<int> *> trees(6);
    for (int i = 0; i < 6; ++i) {
        trees[i] = new BSTFCI<int>;
    }

    trees[0]->add(5, trees[0]->getRoot());
    trees[0]->add(3, trees[0]->getRoot());
    trees[0]->add(2, trees[0]->getRoot());
    trees[0]->add(4, trees[0]->getRoot());
    trees[0]->add(1, trees[0]->getRoot());
    trees[0]->add(7, trees[0]->getRoot());
    trees[0]->add(9, trees[0]->getRoot());
    trees[0]->add(8, trees[0]->getRoot());
    trees[0]->add(10, trees[0]->getRoot());

    /*
     *           5
     *          / \
     *         3   7
     *        / \   \
     *       2   4   9
     *      /       / \
     *     1       8   10
     */

    trees[1]->add(9, trees[1]->getRoot());
    trees[1]->add(8, trees[1]->getRoot());
    trees[1]->add(10, trees[1]->getRoot());

    /*
     *          9
     *         / \
     *        8   10
     */

    cout << endl;
    trees[0]->isSubTree(trees[0], trees[1]) ? cout << "Second tree is subtree from first one\n" :
    cout << "Second tree is not subtree from first one\n";
    cout << endl;

    trees[2]->add(3, trees[2]->getRoot());
    trees[2]->add(2, trees[2]->getRoot());
    trees[2]->add(4, trees[2]->getRoot());
    trees[2]->add(1, trees[2]->getRoot());

    /*
     *         3
     *        / \
     *       2   4
     *      /
     *     1
     */

    trees[0]->isSubTree(trees[0], trees[2]) ? cout << "Third tree is subtree from first one\n" :
    cout << "Third tree is not subtree from first one\n";
    cout << endl;

    trees[3]->add(3, trees[3]->getRoot());
    trees[3]->add(2, trees[3]->getRoot());
    trees[3]->add(4, trees[3]->getRoot());
    trees[3]->add(1, trees[3]->getRoot());
    trees[3]->add(5, trees[3]->getRoot());
    /*
     *         3
     *        / \
     *       2   4
     *      /     \
     *     1       5
     */
    trees[0]->isSubTree(trees[0], trees[3]) ? cout << "Fourth tree is subtree from first one\n" :
    cout << "Fourth tree is not subtree from first one\n";
    cout << endl;

    trees[4]->add(9, trees[4]->getRoot());
    trees[4]->add(8, trees[4]->getRoot());
    trees[4]->add(10, trees[4]->getRoot());
    trees[4]->add(1, trees[4]->getRoot());
    /*
     *
     *          9
     *         / \
     *        8   10
     *       /
     *      1
     */
    trees[0]->isSubTree(trees[0], trees[4]) ? cout << "Fifth tree is subtree from first one\n" :
    cout << "Fifth tree is not subtree from first one\n";
    cout << endl;

    trees[5]->add(5, trees[5]->getRoot());
    trees[5]->add(3, trees[5]->getRoot());
    trees[5]->add(2, trees[5]->getRoot());
    trees[5]->add(4, trees[5]->getRoot());
    trees[5]->add(1, trees[5]->getRoot());
    trees[5]->add(7, trees[5]->getRoot());
    trees[5]->add(9, trees[5]->getRoot());
    trees[5]->add(8, trees[5]->getRoot());
    trees[5]->add(10, trees[5]->getRoot());
    trees[5]->add(11, trees[5]->getRoot());

    /*
     *           5
     *          / \
     *         3   7
     *        / \   \
     *       2   4   9
     *      /       / \
     *     1       8   10
     *                  \
     *                  11
     */
    trees[0]->isSubTree(trees[0], trees[5]) ? cout << "Sixth tree is subtree from first one\n" :
    cout << "Sixth tree is not subtree from first one\n";
    cout << endl;

}

int main() {
    testCases1();
    testCases2();

    return 0;
}

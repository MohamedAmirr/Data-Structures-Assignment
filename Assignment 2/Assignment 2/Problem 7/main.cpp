#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int val) {
        this->key = val;
        this->left = this->right = nullptr;
    }
};

class BST {
private:
    Node *root;
public:
    BST() {
        root = nullptr;
    }

    BST(int val) {
        root = new Node(val);
        root->left = root->right = nullptr;
    }

    void flip(Node *node = nullptr)  // void flip(Node* node = root) ??
    {
        if (node == nullptr) {
            node = root;
        }

        if (node->left != nullptr)flip(node->left);
        if (node->right != nullptr)flip(node->right);
        swap(node->left, node->right);
    }

    void preorder(Node *root) {
        if (root == nullptr) {
            return;
        }

        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }

    Node *getRoot() {
        return root;
    }

    void destroy(Node *node){
        if(node!= nullptr){
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    ~BST(){
        destroy(root);
    }
};


int main() {
    //Test case 1
    BST *t1 = new BST(1);
    t1->getRoot()->left = new Node(2);
    t1->getRoot()->right = new Node(3);
    t1->getRoot()->left->left = new Node(4);
    t1->getRoot()->left->right = new Node(5);
    cout << "Before Flipping: ";
    t1->preorder(t1->getRoot());
    cout << endl;
    t1->flip(t1->getRoot());
    cout << "After Flipping: ";
    t1->preorder(t1->getRoot());
    cout << endl << endl;

    //Test case 2
    BST *t2 = new BST(6);
    t2->getRoot()->left = new Node(7);
    t2->getRoot()->right = new Node(8);
    t2->getRoot()->left->left = new Node(9);
    t2->getRoot()->left->right = new Node(10);
    cout << "Before Flipping: ";
    t2->preorder(t2->getRoot());
    cout << endl;
    t2->flip(t2->getRoot());
    cout << "After Flipping: ";
    t2->preorder(t2->getRoot());
    cout << endl << endl;

    //Test case 3
    BST *t3 = new BST(2);
    t3->getRoot()->left = new Node(4);
    t3->getRoot()->right = new Node(6);
    t3->getRoot()->left->left = new Node(8);
    cout << "Before Flipping: ";
    t3->preorder(t3->getRoot());
    cout << endl;
    t3->flip(t3->getRoot());
    cout << "After Flipping: ";
    t3->preorder(t3->getRoot());
    cout << endl << endl;

    // Test case 4
    BST *t4 = new BST(1);
    t4->getRoot()->left = new Node(3);
    t4->getRoot()->right = new Node(5);
    t4->getRoot()->left->right = new Node(7);
    cout << "Before Flipping: ";
    t4->preorder(t4->getRoot());
    cout << endl;
    t4->flip(t4->getRoot());
    cout << "After Flipping: ";
    t4->preorder(t4->getRoot());
    cout << endl << endl;

    // Test case 5
    BST *t5 = new BST(10);
    t5->getRoot()->left = new Node(20);
    t5->getRoot()->right = new Node(30);
    t5->getRoot()->right->left = new Node(40);
    t5->getRoot()->right->right = new Node(50);
    cout << "Before Flipping: ";
    t5->preorder(t5->getRoot());
    cout << endl;
    t5->flip(t5->getRoot());
    cout << "After Flipping: ";
    t5->preorder(t5->getRoot());
    cout << endl;

    return 0;
}
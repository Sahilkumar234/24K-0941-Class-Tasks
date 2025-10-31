#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* parent;

    BinaryTree() {
        parent = nullptr;
    }

    Node* createNode(int val) {
        return new Node(val);
    }

    int countNodes(Node* N1) {
        if (N1 == NULL)  {
            return 0;
        } 
        return 1 + countNodes(N1->left) + countNodes(N1->right);
    }

    int countLeafNodes(Node* N1) {
        if (N1 == NULL) {
            return 0;
        } 
        if (N1->left == NULL && N1->right == NULL) {
            return 1;
        }
        return countLeafNodes(N1->left) + countLeafNodes(N1->right);
    }

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    BinaryTree T1;

    T1.parent = T1.createNode(1);
    T1.parent->left = T1.createNode(2);
    T1.parent->right = T1.createNode(3);
    T1.parent->left->left = T1.createNode(4);
    T1.parent->left->left->left = T1.createNode(7);
    T1.parent->left->right = T1.createNode(5);
    T1.parent->right->right = T1.createNode(6);

    cout << "Total Nodes: " << T1.countNodes(T1.parent) << endl;
    cout << "Leaf Nodes: " <<T1.countLeafNodes(T1.parent) << endl;
    cout << "Height of Tree: " << T1.height(T1.parent) << endl;

    return 0;
}

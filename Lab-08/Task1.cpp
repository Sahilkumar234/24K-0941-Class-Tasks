#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data) {
        left = right = NULL;
    }
};

Node* createNode(int data) {
    Node* newNode = new Node(data);
    return newNode;
}

Node* insertNode(Node* parent,int newData) {
    if(parent == NULL) {
        return createNode(newData);
    }
    if(newData < parent->data) {
        parent->left = insertNode(parent->left,newData);
    } else if(newData > parent->data) {
        parent->right = insertNode(parent->right,newData);
    }
    return parent;
}

void displayTree(Node* parentNode) {
    if(parentNode == NULL) {
        return;
    } 
    displayTree(parentNode->left);
    cout<<parentNode->data<<" ";
    displayTree(parentNode->right);
}

int main() {
    Node* root = createNode(4);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);
    displayTree(root);
    return 0;
}

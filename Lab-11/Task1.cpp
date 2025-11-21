#include <iostream>
using namespace std;
const int SIZE = 10;

class Node {
public:
    string value;
    Node* next;
    Node() {
        next = NULL;
    }
    Node(string val) {
        value = val;
        next = NULL;
    }
};

int HashFunction(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum += int(key[i]);
    }
    return sum;
}

class Chaining {
public:
    Node* alphabets[SIZE];

    Chaining() {
        for (int i = 0; i < SIZE; i++) {
            alphabets[i] = NULL;
        }
    }

    void insert(string key) {
        int newKey = HashFunction(key);
        int index = newKey % SIZE;

        Node* newNode = new Node(key);

        if (alphabets[index] == NULL) {
            alphabets[index] = newNode;
        } else {
            Node* tmp = alphabets[index];
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            Node* tmp = alphabets[i];
            while (tmp != NULL) {
                cout << tmp->value << " -> ";
                tmp = tmp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    Chaining C;
    C.insert("apple");
    C.insert("mango");
    C.insert("apple");
    C.insert("banana");
    C.insert("grapes");
    C.insert("peach");

    C.display();
}

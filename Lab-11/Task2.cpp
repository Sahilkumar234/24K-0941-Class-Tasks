#include<iostream>
using namespace std;

const int SIZE = 100;

class Node {
public:
    string data;
    Node* next;
    Node() { data = ""; next = NULL; }
    Node(string data) : data(data) { next = NULL; }
};

int changeHash(string value) {
    int n = value.length();
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += int(value[i]);
    }
    return sum;
}

class Dictionary {
public:
    Node* books[SIZE];
    Dictionary() {
        for(int i=0;i<SIZE;i++) {
            books[i] = NULL;
        }
    }

    void addRecord(string book) {
        int key = changeHash(book);
        int index = key % SIZE;
        Node* newNode = new Node(book);
        if(books[index] == NULL) {
            books[index] = newNode;
        } else {
            Node* tmp = books[index];
            while(tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }

    string search(string bookSearch) {
        int newKey = changeHash(bookSearch);
        int index = newKey % SIZE;
        Node* tmp = books[index];
        while(tmp != NULL) {
            if(tmp->data == bookSearch) {
                return bookSearch;
            }
            tmp = tmp->next;
        }
        return "";
    }

    void display() {
        for(int i=0;i<SIZE;i++) {
            cout<<i<<": ";
            Node* tmp = books[i];
            while(tmp != NULL) {
                cout<<tmp->data<<" -> ";
                tmp = tmp->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};

int main() {
    Dictionary D;
    D.addRecord("Atomic");
    D.addRecord("Monk");
    D.addRecord("Alizeh");
    D.addRecord("Rich");
    D.addRecord("Dad");
    D.display();
    D.search("Monk");
}

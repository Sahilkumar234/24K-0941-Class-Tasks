#include <iostream>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

void insert(Node*& head, string name, int score) {
    Node* newNode = new Node{name, score, NULL};
    if (!head) {
        head = newNode;
    } else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = newNode;
    }
}

int getMax(Node* head) {
    int max = 0;
    while (head != NULL) {
        if (head->score > max){
            max = head->score;
        }
        head = head->next;
    }
    return max;
}

int getDigit(int num, int exp) {
    return (num / exp) % 10;
}

Node* concatenate(Node* buckets[]) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < 10; i++) {
        if (buckets[i]) {
            if (!head) {
                head = buckets[i];
                tail = buckets[i];
                while (tail->next) tail = tail->next;
            } else {
                tail->next = buckets[i];
                while (tail->next) tail = tail->next;
            }
        }
    }
    return head;
}

void radixSort(Node*& head) {
    int mx = getMax(head);
    for (int exp = 1; mx / exp > 0; exp *= 10) {
        Node* buckets[10] = {NULL};
        Node* tails[10] = {NULL};
        Node* curr = head;
        while (curr) {
            int d = getDigit(curr->score, exp);
            Node* next = curr->next;
            curr->next = NULL;
            if (!buckets[d]) {
                buckets[d] = curr;
                tails[d] = curr;
            } else {
                tails[d]->next = curr;
                tails[d] = curr;
            }
            curr = next;
        }
        head = concatenate(buckets);
    }
}

void display(Node* head) {
    while (head) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "Enter name and score: ";
        cin >> name >> score;
        insert(head, name, score);
    }
    radixSort(head);
    cout<<endl;
    cout << "Sorted list:"<<endl;
    display(head);
    return 0;
}

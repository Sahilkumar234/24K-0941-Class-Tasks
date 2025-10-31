#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void insert(Node*& head, int val) {
    Node* n = new Node{val,NULL};
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

int getMax(Node* head) {
    int mx = 0;
    while (head != NULL) {
        if (head->value > mx) {
            mx = head->value;
        }
        head = head->next;
    }
    return mx;
}

Node* concatBuckets(Node* buckets[]) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < 10; i++) {
        if (buckets[i]) {
            if (!head) {
                head = buckets[i];
                tail = buckets[i];
                while (tail->next != NULL) {
                    tail = tail->next;
                }
            } else {
                tail->next = buckets[i];
                while (tail->next != NULL) {
                    tail = tail->next;
                }
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
            int d = (curr->value / exp) % 10;
            Node* next = curr->next;
            curr->next = nullptr;
            if (!buckets[d]) {
                buckets[d] = curr;
                tails[d] = curr;
            } else {
                tails[d]->next = curr;
                tails[d] = curr;
            }
            curr = next;
        }
        head = concatBuckets(buckets);
    }
}

void display(Node* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter number of transactions: ";
    cin >> n;
    cout << "Enter transaction amounts: "<<endl;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(head, val);
    }
    radixSort(head);
    cout << "Sorted transactions: "<<endl;
    display(head);
    return 0;
}

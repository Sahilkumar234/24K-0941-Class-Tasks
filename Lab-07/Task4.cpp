#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val) : data(val) {
	next = NULL;
	}
};
class SinglyList {
private:
    Node* head;
    Node* getTail(Node* cur) {
        while (cur && cur->next)
            cur = cur->next;
        return cur;
    }
    Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node *prev = NULL, *cur = head, *tail = pivot;

        while (cur != pivot) {
            if (cur->data < pivot->data) {
                if (!(*newHead))
                    (*newHead) = cur;
                prev = cur;
                cur = cur->next;
            } else {
                if (prev)
                    prev->next = cur->next;
                Node* tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if (!(*newHead))
            (*newHead) = pivot;

        (*newEnd) = tail;
        return pivot;
    }
    Node* quickSortRecur(Node* head, Node* end) {
        if (!head || head == end)
            return head;

        Node *newHead = NULL, *newEnd = NULL;
        Node* pivot = partition(head, end, &newHead, &newEnd);
        if (newHead != pivot) {
            Node* tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = NULL;

            newHead = quickSortRecur(newHead, tmp);

            Node* tail = getTail(newHead);
            tail->next = pivot;
        }
        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }
public:
    SinglyList() : head(NULL) {}
    void insert(int val) {
        Node* newNodePtr = new Node(val);
        if (!head) {
            head = newNodePtr;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNodePtr;
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void quickSort() {
        head = quickSortRecur(head, getTail(head));
    }
};
int main() {
    SinglyList list;

    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        list.insert(arr[i]);

    cout << "Original list: ";
    list.display();

    list.quickSort();

    cout << "Sorted list:   ";
    list.display();

    return 0;
}

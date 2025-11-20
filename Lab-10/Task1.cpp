#include <iostream>
using namespace std;

class MinHeap {
public:
    int arr[100];
    int size;

    MinHeap() {
        size = 0;
    }
    void insert(int val) {
        arr[size] = val;
        int i = size;
        size++;
        while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
            int temp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);

    cout << "Initial Heap: ";
    h.display();
    h.insert(2);
    cout << "Updated Heap: ";
    h.display();
    return 0;
}


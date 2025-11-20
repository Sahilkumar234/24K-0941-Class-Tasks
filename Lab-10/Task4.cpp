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
    void removeMin() {
        if (size == 0) return;
        arr[0] = arr[size - 1];
        size--;
        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if (left < size && arr[left] < arr[smallest]) smallest = left;
            if (right < size && arr[right] < arr[smallest]) smallest = right;
            if (smallest == i) break;
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            i = smallest;
        }
    }
    void display() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};
int main() {
    MinHeap h;
    h.insert(100);
    h.insert(50);
    h.insert(75);
    h.insert(60);

    cout << "Initial Heap: ";
    h.display();
    h.insert(55);
    cout << "After inserting 55: ";
    h.display();
    h.removeMin();
    cout << "After removing lowest price: ";
    h.display();
    return 0;
}

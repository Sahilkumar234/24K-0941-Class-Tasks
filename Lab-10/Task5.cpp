#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[100];
    int size;

    MaxHeap() {
        size = 0;
    }
    void insert(int val) {
        arr[size] = val;
        int i = size;
        size++;
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            int temp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
    void removeMax() {
        if (size == 0) return;
        arr[0] = arr[size - 1];
        size--;
        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;
            if (left < size && arr[left] > arr[largest]) largest = left;
            if (right < size && arr[right] > arr[largest]) largest = right;
            if (largest == i) break;
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest;
        }
    }
    void display() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};
int main() {
    MaxHeap h;
    h.insert(1500);
    h.insert(1200);
    h.insert(1800);
    h.insert(1600);

    cout << "Initial Queue: ";
    h.display();
    h.insert(1700);
    cout << "After inserting 1700: ";
    h.display();
    h.removeMax();
    cout << "After matching highest rated player: ";
    h.display();
    return 0;
}

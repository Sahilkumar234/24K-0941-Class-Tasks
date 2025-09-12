#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* array;        
    int size;          
    int capacity;  
public:
     
    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = array[i];
        }

        delete[] array;
        array = newData;
        capacity = newCapacity;
    }
 
    DynamicArray(int initialCapacity = 2) {
        capacity = initialCapacity;
        size = 0;
        array = new int[capacity];
    }
    ~DynamicArray() {
        delete[] array;
    }
    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        array[size++] = value;
    }
    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    cout << "Elements in array: ";
    arr.print();

    return 0;
}

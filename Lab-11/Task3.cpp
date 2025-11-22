#include <iostream>
using namespace std;
const int SIZE = 10;

class Hashing {
public:
    int* arr;
    int count;

    Hashing() {
        count = 0;
        arr = new int[SIZE];
        for(int i = 0; i < SIZE; i++) {
            arr[i] = -1;
        }
    }

    void insert(int val) {
        if (count == SIZE) {
            cout << "Hash table full!" << endl;
            return;
        }

        int index = val % SIZE;

        while (arr[index] != -1) {
            index = (index + 1) % SIZE;
        }
        arr[index] = val;
        count++;
    }

    void deleteHash(int val) {
        int index = val % SIZE;
        int start = index;

        while (arr[index] != -1) {
            if (arr[index] == val) {
                arr[index] = -1;
                return;
            }
            index = (index + 1) % SIZE;

            if (index == start) {
                break;
            }
        }

        cout << "Value not found!" << endl;
    }

    void search(int key) {
        int index = key % SIZE;
        int start = index;

        while (arr[index] != -2) {
            if (arr[index] == key) {
                cout << "Found: " << key << " at index: "<<index<<endl;
                return;
            }
            index = (index + 1) % SIZE;

            if (index == start){
                break; 
            }

        cout << "Not found" << endl;
    }
}

    void displayFunc() {
        for(int i = 0; i < SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Hashing H;
    H.insert(3);
    H.insert(44);
    H.insert(23);
    H.insert(98);
    H.insert(8);
    H.displayFunc();

    H.deleteHash(44);
    H.displayFunc();

    H.search(23);
}

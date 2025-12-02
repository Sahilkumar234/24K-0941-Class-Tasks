#include <iostream>
using namespace std;

const int SIZE = 10;

class LinearHashing {
public:
    int arr[SIZE];

    LinearHashing() {
        for (int i = 0; i < SIZE; i++) {
            arr[i] = -1; 
        }
    }

    void insert(int newElem) {
        int index = newElem % SIZE;
        int startIndex = index;

        while (arr[index] != -1) {
            index = (index + 1) % SIZE;

            if (index == startIndex) {
                cout << "Hash Table is FULL!!" << endl;
                return;
            }
        }

        arr[index] = newElem;
        cout << "Inserted: " << newElem << endl;
    }

    void removeKey(int key) {
        int index = key % SIZE;
        int startIndex = index;

        while (arr[index] != -1) {
            if (arr[index] == key) {
                cout << "Element " << key << " deleted" << endl;
                arr[index] = -1; 
                return;
            }
            index = (index + 1) % SIZE;

            if (index == startIndex)
                break;
        }

        cout << "Not found for deletion" << endl;
    }

    void search(int key) {
        int index = key % SIZE;
        int startIndex = index;

        while (arr[index] != -1) {
            if (arr[index] == key) {
                cout << "Element " << key << " Found at index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;

            if (index == startIndex)
                break;
        }

        cout << "Not Found" << endl;
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] == -1)
                cout << i << " : EMPTY" << endl;
            else
                cout << i << " : " << arr[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    LinearHashing H;
    int choice, value;

    do {
        cout<<endl;
        cout << "===== MENU ====="<<endl;
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            H.insert(value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            H.search(value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            H.removeKey(value);
            break;

        case 4:
            H.display();
            break;

        case 5:
            cout << "Exiting..."<<endl;
            break;

        default:
            cout << "Invalid choice!"<<endl;
        }

    } while (choice != 5);

    return 0;
}

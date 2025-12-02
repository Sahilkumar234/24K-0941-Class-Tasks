#include <iostream>
using namespace std;

const int SIZE = 15;

class StudentHashTable {
private:
    int roll[SIZE];
    string name[SIZE];

public:
    StudentHashTable() {
        for (int i = 0; i < SIZE; i++) {
            roll[i] = -1;  
            name[i] = "";
        }
    }
    void InsertRecord(int r, string n) {
        int index = r % SIZE;
        int attempt = 0;

        while (attempt < SIZE) {
            int newIndex = (index + attempt * attempt) % SIZE;
            if (roll[newIndex] == -1) {
                roll[newIndex] = r;
                name[newIndex] = n;
                cout << "Record Inserted at index " << newIndex << endl;
                return;
            }

            attempt++;
        }

        cout << "Hash Table is FULL! Cannot Insert.\n";
    }
    void SearchRecord(int r) {
        int index = r % SIZE;
        int attempt = 0;

        while (attempt < SIZE) {
            int newIndex = (index + attempt * attempt) % SIZE;

            if (roll[newIndex] == r) {
                cout << "Record Found: Roll = " << r 
                     << ", Name = " << name[newIndex] << endl;
                return;
            }

            attempt++;
        }

        cout << "Record not found\n";
    }
    void DisplayTable() {
        cout << "\n--- Student Hash Table ---\n";
        for (int i = 0; i < SIZE; i++) {
            if (roll[i] != -1)
                cout << "Index " << i << ": Roll = " << roll[i]
                     << ", Name = " << name[i] << endl;
            else
                cout << "Index " << i << ": (empty)\n";
        }
        cout << endl;
    }
};


int main() {
    StudentHashTable ht;

    ht.InsertRecord(101, "Ali");
    ht.InsertRecord(56, "Sana");
    ht.InsertRecord(200, "Rohit");
    ht.InsertRecord(41, "John");
    ht.InsertRecord(89, "Mary");

    cout << "\nSearching Records:\n";
    ht.SearchRecord(200);
    ht.SearchRecord(89);
    ht.SearchRecord(999); 

    ht.DisplayTable();

    return 0;
}

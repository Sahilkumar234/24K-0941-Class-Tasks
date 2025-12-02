#include<iostream>
using namespace std;
const int SIZE = 15;

class QuadraticProb {
    public:
    int rollNO[SIZE];
    string name[SIZE];

    QuadraticProb() {
        for(int i=0;i<SIZE;i++) {
            rollNO[i] = -1;
            name[i] = "";
        }
    }

    void insertRecord(int rollNum,string studName) {
        int index = rollNum % SIZE;
        int attempt = 0;

        while(attempt < SIZE) {
            int newIndex = (index + (attempt * attempt)) % SIZE;

            if(rollNO[newIndex] == -1) {
                rollNO[newIndex] = rollNum;
                name[newIndex] = studName;
                cout<<"Record inserted at index: "<<newIndex<<endl;
                return;
            }
            attempt++;
        }
        cout<<"Hash Table is FULL now!!"<<endl;
    }

    void searchRecord(int searchRoll) {
        int index = searchRoll % SIZE;
        int attempt = 0;

        while(attempt < SIZE) {
            int newIndex = (index + (attempt*attempt)) % SIZE;
            if(rollNO[newIndex] == searchRoll) {
                cout<<"Record found => Roll NO: "<<rollNO[index]<<" Name: "<<name[newIndex]<<endl;
                return;
            }
            attempt++;
        }
        cout<<"Not Found"<<endl;
    }

    void display() {
        cout<<"Student Hash Table"<<endl;

        for(int i=0;i<SIZE;i++) {
            if(rollNO[i] != -1) {
                cout<<"Index "<<i<<": Roll No => "<<rollNO[i]<<" || Name => "<<name[i]<<endl;
            } else {
                cout<<"Index "<<i<<": is empty"<<endl;
            }
        }
        cout<<endl;
    }
};

int main() {
    QuadraticProb ht;

    ht.insertRecord(101, "Ali");
    ht.insertRecord(56, "Sana");
    ht.insertRecord(200, "Rohit");
    ht.insertRecord(41, "John");
    ht.insertRecord(89, "Mary");

    cout<<endl;
    cout << "Searching Records: "<<endl;
    ht.searchRecord(200);
    ht.searchRecord(89);
    ht.searchRecord(999);  

    ht.display();

    return 0;
}

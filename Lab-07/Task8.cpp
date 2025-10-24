#include <iostream>
#include <string>
using namespace std;

class Input11 {
public:
    string names[10];
    int scores[10];
    int totPrice[10];

    void takeInput() {
        cin.ignore();
        for (int i = 0; i < 5; i++) {
            cout << "Enter name " << i + 1 << ": ";
            getline(cin, names[i]);
            cout << "Enter score " << i + 1 << ": ";
            cin >> scores[i];
            cout << "Enter Total Price " << i + 1 << ": ";
            cin >> totPrice[i];
            cin.ignore();
        }
    }

    void quickSort(int low, int high) {
        if (low < high) {
            int pivotIndex = partition(low, high);
            quickSort(low, pivotIndex - 1);
            quickSort(pivotIndex + 1, high);
        }
    }
    int partition(int low, int high) {
        int pivot = totPrice[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (totPrice[j] <= pivot) {
                i++;
                swapData(i, j);
            }
        }
        swapData(i + 1, high);
        return i + 1;
    }
    void swapData(int a, int b) {
        swap(totPrice[a], totPrice[b]);
        swap(scores[a], scores[b]);
        swap(names[a], names[b]);
    }
    void display() {
        cout << "Sorted list (Ascending by Total Price): "<<endl;
        for (int i = 0; i < 10; i++) {
            cout << names[i] << " - Score: " << scores[i]
                 << " - Total Price: " << totPrice[i] << endl;
        }
    }
};

int main() {
    Input11 obj;
    cout << "Enter 5 names, scores, and total prices: "<<endl;
    obj.takeInput();

    obj.quickSort(0, 4);
    obj.display();

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Input11 {
public:
    string names[10];
    int scores[10];

    void takeInput() {
        for (int i = 0; i < 10; i++) {
            cout << "Enter name " << i + 1 << ": ";
            cin.ignore();
            getline(cin, names[i]);
            cout << "Enter score " << i + 1 << ": ";
            cin >> scores[i];
        }
    }
    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }
    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int tempScoresL[n1], tempScoresR[n2];
        string tempNamesL[n1], tempNamesR[n2];

        for (int i = 0; i < n1; i++) {
            tempScoresL[i] = scores[left + i];
            tempNamesL[i] = names[left + i];
        }
        for (int j = 0; j < n2; j++) {
            tempScoresR[j] = scores[mid + 1 + j];
            tempNamesR[j] = names[mid + 1 + j];
        }
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (tempScoresL[i] >= tempScoresR[j]) {
                scores[k] = tempScoresL[i];
                names[k] = tempNamesL[i];
                i++;
            } else {
                scores[k] = tempScoresR[j];
                names[k] = tempNamesR[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            scores[k] = tempScoresL[i];
            names[k] = tempNamesL[i];
            i++;
            k++;
        }
        while (j < n2) {
            scores[k] = tempScoresR[j];
            names[k] = tempNamesR[j];
            j++;
            k++;
        }
    }
    void display() {
        cout << "Sorted list:"<<endl;
        for (int i = 0; i < 10; i++) {
            cout << names[i] << " - " << scores[i] << endl;
        }
    }
};

int main() {
    Input11 obj;
    cout << "Enter 10 names and scores:"<<endl;
    obj.takeInput();

    obj.mergeSort(0, 9);
    obj.display();

    return 0;
}

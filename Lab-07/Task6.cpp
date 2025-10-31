#include <iostream>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
};

void merge(Employee a[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    Employee *L = new Employee[n1];
    Employee *R = new Employee[n2];
    for (int i = 0; i < n1; i++){
        L[i] = a[low + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i].salary >= R[j].salary) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    while (i < n1){
       a[k++] = L[i++];
    }
    while (j < n2) {
        a[k++] = R[j++];
    }
    delete[] L;
    delete[] R;
}

void mergeSort(Employee a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    Employee e[12];
    cout << "Enter 12 employee records (Name ID Salary):\n";
    for (int i = 0; i < 12; i++){
        cin >> e[i].name >> e[i].id >> e[i].salary;
    }
    mergeSort(e, 0, 11);
    cout<<endl;
    cout << "Top 3 highest-paid employees: "<<endl;
    for (int i = 0; i < 3; i++)
        cout << e[i].name << " " << e[i].id << " " << e[i].salary << endl;
    return 0;
}

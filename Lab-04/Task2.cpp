#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}
int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}
int selectionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
    return comparisons;
}
int shellSort(int arr[], int n) {
    int comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap) {
                comparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                } else break;
            }
            arr[j] = temp;
        }
    }
    return comparisons;
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int n;
    cout << "Enter size of array (20 or 100): ";
    cin >> n;
    int arr[100];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int arr1[100], arr2[100], arr3[100], arr4[100];
    copyArray(arr, arr1, n);
    copyArray(arr, arr2, n);
    copyArray(arr, arr3, n);
    copyArray(arr, arr4, n);

    cout << "Original Array: ";
    printArray(arr, n);

    int cmp1 = bubbleSort(arr1, n);
    cout << "Bubble Sort Result: ";
    printArray(arr1, n);
    cout << "Comparisons: " << cmp1 << endl;

    int cmp2 = insertionSort(arr2, n);
    cout << "Insertion Sort Result: ";
    printArray(arr2, n);
    cout << "Comparisons: " << cmp2 << endl;

    int cmp3 = selectionSort(arr3, n);
    cout << "Selection Sort Result: ";
    printArray(arr3, n);
    cout << "Comparisons: " << cmp3 << endl;

    int cmp4 = shellSort(arr4, n);
    cout << "Shell Sort Result: ";
    printArray(arr4, n);
    cout << "Comparisons: " << cmp4 << endl;

    return 0;
}

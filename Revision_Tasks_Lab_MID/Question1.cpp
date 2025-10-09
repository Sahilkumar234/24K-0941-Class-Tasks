#include<iostream>
using namespace std
;
// <= REASON:1 =>

// Shell Sort compares far elements and their requires less iteration then insertion sort that's
// why here shell sort will be the best.

void shellSort(int arr[],int n) {
    for(int gap = n/2;gap > 0;gap /= 2) {
        for(int i=gap;i<n;i++) {
            int j = i;
            int temp = arr[i];
            while(j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = temp;
        }
    }
}

void printArr(int arr[],int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {205,102,310,450,120,90};
    int n = sizeof(arr) / sizeof(int);

    cout<<"Original Array...."<<endl;
    printArr(arr,n);

    cout<<"\nAfter sorting array..."<<endl;
    shellSort(arr,n);
    printArr(arr,n);
}

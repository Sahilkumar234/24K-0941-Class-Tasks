#include<iostream>
using namespace std;

// <<== REASON-01 ==>>  
// Airpot refers Shell sort because it is faster and quicker in luggage Processing,it also
// takes less comparisons and it is efficient even if luggage weight is random


// <<== REASON-02 ==>>
//  If luggage is already sorted then shell sort becomes more Faster..

void shellSort(int arr[],int n) {
    for(int gap = n / 2;gap > 0;gap /= 2) {
        for(int i = gap;i < n;i++) {
            int temp = arr[i];
            int j = i;
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
    int arr[] = {32,25,40,12,18,50,28};
    int n = sizeof(arr) / sizeof(int);

    cout<<"Original Array...."<<endl;
    printArr(arr,n);

    cout<<"\nAfter sorting array..."<<endl;
    shellSort(arr,n);
    printArr(arr,n);
}

#include <iostream>
using namespace std;

int compFirst=0, compRand=0, compMid=0, compMed3=0;
unsigned int seedVal = 12345;
int myRand(int low, int high) {
    seedVal = (1103515245 * seedVal + 12345) % 2147483648;
    return low + (seedVal % (high - low + 1));
}

int partitionFirst(int a[], int low, int high) {
    int pivot=a[low];
    int i=low+1, j=high;
    while(true){
        while(i<=high && a[i]<=pivot)
        { 
            compFirst++; i++; 
        }
        while(a[j]>pivot){
         compFirst++; j--; 
        }
        if(i>=j){
            break;
        }
        swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void quickFirst(int a[], int low, int high) {
    if(low<high){
        int p=partitionFirst(a,low,high);
        quickFirst(a,low,p-1);
        quickFirst(a,p+1,high);
    }
}

int partitionRand(int a[], int low, int high) {
    int r=myRand(low,high);
    swap(a[low],a[r]);
    int pivot=a[low];
    int i=low+1, j=high;
    while(true){
        while(i<=high && a[i]<=pivot)
        { 
            compRand++; 
            i++; 
        }
        while(a[j]>pivot){ 
            compRand++; 
            j--; 
        }
        if(i>=j) break;
        swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void quickRand(int a[], int low, int high) {
    if(low<high){
        int p=partitionRand(a,low,high);
        quickRand(a,low,p-1);
        quickRand(a,p+1,high);
    }
}

int partitionMid(int a[], int low, int high) {
    int mid=(low+high)/2;
    swap(a[low],a[mid]);
    int pivot=a[low];
    int i=low+1, j=high;
    while(true){
        while(i<=high && a[i]<=pivot){ 
            compMid++; 
            i++; 
        }
        while(a[j]>pivot){ 
            compMid++; 
            j--; 
        }
        if(i>=j) {
            break;
        }
        swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void quickMid(int a[], int low, int high) {
    if(low<high){
        int p=partitionMid(a,low,high);
        quickMid(a,low,p-1);
        quickMid(a,p+1,high);
    }
}

int medianOfThree(int a[], int low, int high) {
    int mid=(low+high)/2;
    if(a[low]>a[mid]){
        swap(a[low],a[mid]);
    }
    if(a[low]>a[high]) {
        swap(a[low],a[high]);
    }
    if(a[mid]>a[high]) {
        swap(a[mid],a[high]);
    }
    swap(a[low],a[mid]);
    return a[low];
}

int partitionMed3(int a[], int low, int high) {
    int pivot=medianOfThree(a,low,high);
    int i=low+1, j=high;
    while(true){
        while(i<=high && a[i]<=pivot){ 
            compMed3++; 
            i++; 
        }
        while(a[j]>pivot){ 
            compMed3++; 
            j--; 
        }
        if(i>=j) {
            break;
        }
        swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void quickMed3(int a[], int low, int high) {
    if(low<high){
        int p=partitionMed3(a,low,high);
        quickMed3(a,low,p-1);
        quickMed3(a,p+1,high);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int *a1=new int[n];
    int *a2=new int[n];
    int *a3=new int[n];
    int *a4=new int[n];
    for(int i=0;i<n;i++){ a1[i]=a2[i]=a3[i]=a4[i]=arr[i]; }

    quickFirst(a1,0,n-1);
    quickRand(a2,0,n-1);
    quickMid(a3,0,n-1);
    quickMed3(a4,0,n-1);

    cout<<"Comparisons using first element pivot: "<<compFirst<<endl;
    cout<<"Comparisons using random element pivot: "<<compRand<<endl;
    cout<<"Comparisons using middle element pivot: "<<compMid<<endl;
    cout<<"Comparisons using median of three pivot: "<<compMed3<<endl;
    cout<<endl;

    delete[] arr;
    delete[] a1;
    delete[] a2;
    delete[] a3;
    delete[] a4;
    return 0;
}

#include<iostream>
using namespace std;

int sumOfDigits(int num) {
    if (num / 10 == 0)
        return num;

    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sumOfDigits(sum);
}

int main() {
    int n;
    cout<<"Enter number: ";
    cin>>n;

    int sum = sumOfDigits(n);
    cout << sum << endl; 
}

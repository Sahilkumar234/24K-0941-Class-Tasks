#include <iostream>
using namespace std;

struct Product {
    string name;
    float price;
    string description;
    bool availability;
};
void swap(Product &a, Product &b) {
    Product temp = a;
    a = b;
    b = temp;
}
int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void displayProducts(Product arr[], int n) {
    cout << "Sorted Product List by Price: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].name << endl;
        cout << "Price: $" << arr[i].price << endl;
        cout << "Description: " << arr[i].description << endl;
        cout << "Availability: " << (arr[i].availability ? "In Stock" : "Out of Stock") << endl;
    }
}
int main() {
    const int n = 3;
    Product products[n];
    cout << "Enter details for 3 products: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Product " << i + 1 << ": "<<endl;
        cout << "Name: ";
        cin >> ws;
        getline(cin, products[i].name);

        cout << "Price: ";
        cin >> products[i].price;

        cout << "Description: ";
        cin >> ws;
        getline(cin, products[i].description);

        cout << "Availability (1 for In Stock, 0 for Out of Stock): ";
        cin >> products[i].availability;
    }
    quickSort(products, 0, n - 1);
    displayProducts(products, n);

    return 0;
}

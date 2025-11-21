#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size of array:" << endl;
    cin >> size;
    int* arr = new int[size];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Array elements are:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
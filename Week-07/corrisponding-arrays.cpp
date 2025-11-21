#include <iostream>
using namespace std;
int main() {
    int A[4], B[4];
    bool same = true;
    cout << "Enter 4 elements for array A:" << endl;
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    cout << "Enter 4 elements for array B:" << endl;
    cin >> B[0] >> B[1] >> B[2] >> B[3];
    for (int i = 0; i < 4; i++) {
        if (A[i] != B[i]) {
            same = false;
            break;
        }
    }
    switch (same) {
        case true:
            cout << "Arrays are identical." << endl;
            break;
        case false:
            cout << "Arrays are not identical." << endl;
            break;
    }
    return 0;
}
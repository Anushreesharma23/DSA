#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the array: " << length << endl;
    
    return 0;
}

#include <iostream>
using namespace std;

int Search (int arr[], int number) {
    int count = 0;
    int i = 0;

    while (arr[i] != 0) {
        if (arr[i] == number) {
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    int arr[] = {2, 5, 8, 3, 9, 3, 5, 7, 2, 6, 8, 9};
    int number;
    cin >> number;  
    int result = Search(arr, number);
    if (result != 0) {
        cout << number << " xuat hien " << result << " lan";
    } else {
        cout << "Khong tim thay " << number << " trong mang";
    }

    return 0;
}

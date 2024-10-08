#include <iostream>
using namespace std;

int binarySearchAlgorithm(int arr[], int left, int right, int num2Search){
    while (left <= right){
        int mid = left + (right - left / 2); // -> if we divide just (right-left) / 2, it will not give us a correct result when left != 0.

        if (arr[mid] == num2Search){
            return mid;
        }
        else if (arr[mid] < num2Search) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // -> the element was not found
}

int main(){
    int arr[10] = {1, 3, 12, 14, 23, 34, 55, 65, 75, 78};
    int num2Search;
    int left = 0; // -> left will always be 0 at first
    int right = (sizeof(arr)/sizeof(arr[0])) - 1; // -> the whole size of the array -1 ... because we need the index value (which is always n-1)

    cout << "Enter the number to search: "; cin >> num2Search;
    int positionFound = binarySearchAlgorithm(arr, left, right, num2Search);

    if(positionFound == -1){
        cout << "Number not found in the array :(" << endl;
    }
    else {
        cout << "Number found at position index " << positionFound << endl;
    }
    
    return 0;
}
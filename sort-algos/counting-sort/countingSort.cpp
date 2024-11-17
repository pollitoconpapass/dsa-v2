#include <iostream>
using namespace std;

void countingSort(int arr[], int sizeOfArr, int range){
    // 1. Create the Output and Count array
    int outputArr[sizeOfArr];
    int countArr[range];

    // 2. Fill count array with 0 as well
    for(int i=0; i<range; i++){
        countArr[i] = 0;
    }

    // 3. Take each value of the input array and search that same number but as index in the countArr and increment in 1
    for(int i=0; i<sizeOfArr; i++){
        ++countArr[arr[i]];
    }

    // 4. Take each value in the count aray and sum (n + (n-1)) and place it at countArr[n]
    for(int i=1; i<range; i++){
        countArr[i] = countArr[i] + countArr[i-1];
    }

    // 5. Make the interpretation process
    for(int i=0; i<sizeOfArr; i++){
        outputArr[--countArr[arr[i]]] = arr[i];
    }

    // 6. Return the final and sorted array
    for(int i=0; i<sizeOfArr; i++){
        arr[i] = outputArr[i];
    }

    // === DISPLAY THE SORTED ARRAY ===
    for(int x=0; x < sizeOfArr; x++){
        cout << arr[x] << " | ";
    }
}


int main(){
    int arr[7] = {1, 4, 1, 2, 7, 5, 2};
    int range = 10;
    int sizeOfArr = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, sizeOfArr, range);
    return 0;
}
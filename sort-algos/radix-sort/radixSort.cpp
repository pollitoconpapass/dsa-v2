#include <iostream>
#include "functions.h"
using namespace std;

void radixSort(int arr[], int size){
    int max = getMax(arr, size);

    for(int div=1; max/div> 0; div*=10){ // -> first time: div =  1 | second time: div = 10 (div = div*10) | third time: div = 100  
    // |-> to take the least significant digit per each iteration
                                        
        countingSort4Radix(arr, size, div); // -> call the counting sort (with some minor changes)
        // see the process in functions.h
    }
}


int main(){
    int arr[8] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr)/sizeof(arr[0]);

    radixSort(arr, size);

    // After the sort
    cout << "=== Sorted Array ===" << endl;
    for(int x=0; x<size; x++){
        cout << arr[x] << " | ";
    }

    return 0;
}
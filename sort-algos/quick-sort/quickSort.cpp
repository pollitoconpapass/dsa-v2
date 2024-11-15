#include <iostream>
using namespace std;

// int swap(int &num1, int &num2){
//     int temp = num1;
//     num1 = num2;
//     num2 = temp;
// }

int Partition(int arr[], int start, int end){
    int pivot = arr[end]; // -> we assign pivot to the last element of the array
    int pIndex = start;  // -> this is gonna keep a track of the elements that are smaller
                        // ... and will increment everytime a smaller element is swapped to the left.

    for(int i=start; i < (end - 1); i++){ // -> It's i till end -1 because the pivot is already at the end. No need to compare them...
        // All the elements are gonna be compared with the pivot:
        if(arr[i] <= pivot){ // -> if the element is smaller or equal to the pivot...
            // swap the positions of that element to the pIndex which at the start of the algorithm the pIndex is gonna be the start 
            // (so it will take the element to the 'start' or the 'beginning')
            int temp = arr[i];
            arr[i] = pivot;
            pivot = temp;

            pIndex++; // -> increment the pIndex to not replace the one already placed.

        }
    }

    // We will send the pivot element to the 'between' of the array 
    int temp = arr[end]; // -> as the pivot element is the last of the list we use arr[end]
    arr[end] = arr[pIndex];
    arr[pIndex] = temp;

    // where all the elements at its left are smaller, and all elements at its right are greater
    // (there's where we want to generate a partition, at the left and right of that 'pivot')

    return pIndex; // -> that's why we return that pIndex (where the pivot is now at)

    // so we can implement quick sort at pivot's left side (from the array beginning to pIndex - 1), and at its right (from pIndex + 1 until the array ends)
}

void quickSort(int arr[], int start, int end){
    if(start < end){  // -> because we can't iterate over an array that starts with a higher or same value than the end
        int p = Partition(arr, start, end);
        quickSort(arr, start, (p-1)); // -> recursive call for left partition
        quickSort(arr, (p+1), end); // -> recursive call for right partition
    }
}

int main(){
    int myArr[5] = {3, 2, 9, 7, 6};
    int size = sizeof(myArr)/ sizeof(myArr[0]); // -> 5 
    quickSort(myArr, 0, (size -1)); // -> (size-1) because we are looking for the index (the index starts at 0)

    cout << "After sorting..." << endl;
    for(int i=0; i<size; i++){
        cout << myArr[i] << " | ";
    }

    return 0;
}
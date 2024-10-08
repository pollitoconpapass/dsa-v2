#include <iostream>
using namespace std;

void bubbleSortAlgorithm(int arr[], int Nsize){
    int i, j, temp;

    for(int i = 0; i < Nsize; i++){ // outer loop
        for(int j = 0; j < (Nsize - i - 1); j++){ // -> inner loop
        // (Nsize - i - 1) makes more sense when the process starts running. 
        /*For 1st time: (5 - 0 - 1) = 4 -> it will go through all the array
        2nd time: (5 - 1 - 1) = 3 -> it will go through the penultimate index of the array (because in the last index will be stored the greatest number, so no need to change it)
        3rd time: (5 - 2 - 1) = 2 -> it will go through the antepenultimate index of the array (like said previously, the last two indexes already contain the two greates numbers, no need to change it)
        ....  */

            if(arr[j] > arr[j + 1]){ // -> if the current element is greater than the one at right, then...
                // ...swap them as we commonly know
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            // like this, the element that is recognized as greater than, will go all the way to the back of the array as j++
            // and once the greatest is at the end, it will get out of this inner loop and go all the way to the outer loop.
        }
    }

    // Show the sorted array
    for(int x = 0; x < Nsize; x++){
        cout << arr[x] << " | ";
    }
}

int main(){
    int arr[5]{9, 7, 3, 6, 2};
    int Nsize = sizeof(arr)/sizeof(arr[0]);
    bubbleSortAlgorithm(arr, Nsize);

    return 0;
}
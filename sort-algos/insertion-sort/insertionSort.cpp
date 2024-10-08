#include <iostream>
using namespace std;

void insertionSortALgorithm(int arr[], int Nsize){
    int i, j, key;

    for(i= 1; i < Nsize; i++){
        key = arr[i]; // -> store the key value here (it will start with the 2nd element in the array)
        j = i - 1; // -> j will be the index i - 1, the previous element of key

        while(j >= 0 && arr[j] > key){ // -> only if j is equal or greater than 0, (cause the indexes starts from 0) 
                                    // ... and only if the value in the j position (the one previous of the key) is greater than key (cause we have to sort it, duh)
            arr[j + 1] = arr[j]; // -> now the j + 1 position (the i position) will store the same value of the j position (double the element before)
            j = j - 1; // -> and we substract 1 to j (to make it 'iter' the array to the left)
        }
        // When j is negative (the array has been 'itered' completely) or the element previous is actually lesser than the key
        arr[j + 1] = key; // -> we assign the predefined and kept key to the j + 1 position
        // As j decreaes, it will stop when the element previous (which has j index) is not greater, so it has to be located at it's right, to actually perform the sort
    }

    // Show the ordered array:
    cout << "Ordered array:" << endl;
    for(int x=0; x < Nsize; x++){
        cout << arr[x] << " | " ;
    }
}

int main(){
    int arr[5] = {9, 7, 3, 6, 2};
    int Nsize = sizeof(arr) / sizeof(arr[0]);
    insertionSortALgorithm(arr, Nsize);

    return 0;
}
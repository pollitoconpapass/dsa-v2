#include <iostream>
using namespace std;

void selectionSortAlgorithm(int arr[], int Nsize){
    int minimum, temp;

    for(int i=0; i < Nsize - 1; i++){ // -> it's Nsize -1 because i starts in 0
        minimum = i; // -> we assign the minimum to i (at the begining is gonna be 0... and while the program runs it will increment by 1)

        for(int j=i+1; j < Nsize; j++){ // -> and here it's Nsize because j starts in 1
            if(arr[j] < arr[minimum]){  // -> if the position of j in the array (one position at right, as j = i + 1) is lower than the one in the minimum
                minimum = j; // -> change the minimum 
            }
        }

        if(minimum != i){ // -> min is supposed to store the lowest element. And the smallest element should be at i position, so if they are not the same...
            // Swap positions between i and the minimum
            temp = arr[minimum];
            arr[minimum] = arr[i];
            arr[i] = temp;
        }
    }

    // Show the ordered list
    cout << "Ordered list" << endl;
    for(int x = 0; x < Nsize; x++){
        cout << "| " << arr[x] << " | ";
    }
}


int main(){
    int arr[5] = {64, 12, 11, 45, 22};
    int Nsize = sizeof(arr) / sizeof(arr[0]);
    selectionSortAlgorithm(arr, Nsize);

    return 0;
}
#include <iostream>
using namespace std;

void bubbleSortOptimized(int arr[], int Nsize){
    int rounds = 0;
    int temp;

    for(int i = 0; i < Nsize; i++){
        rounds++; // -> to check how many iterations took place
        bool flag = false; // -> additional step

        for(int j = 0; j < Nsize - i - 1; j++){ 
            if(arr[j] > arr[j + 1]){ // -> if the element we're comparing is greater than the one at right...
                flag = true; // -> in here we change flag for true... (another additional step)

                // swap:
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        if(flag == false){ // -> if this is the same value as initialized, means that the array already have all the elements sorted
            break; // ... so it breaks to not iterate all over again, cause it will be useless.
        }
    }

    // Show the sorted array: 
    cout << "Number of rounds taken to sort: " << rounds << endl;
    for(int x = 0; x < Nsize; x++){
        cout << " | " << arr[x];
    }
    
}

int main(){
    int arr[5] = {5, 2, 4, 3, 6};
    int Nsize = sizeof(arr) / sizeof(arr[0]);
    bubbleSortOptimized(arr, Nsize);

    return 0;
}
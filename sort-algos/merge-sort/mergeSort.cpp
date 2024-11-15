#include <iostream>
using namespace std;

void merge(int arr[], int left, int medium, int right){
    int i = left; // -> i will be the iterator for the left subarray, so it will start at left
    int j = medium + 1; // -> j will be the iterator for the right subarray, so it will start at medium index + 1
    int k = left; // -> k will be the iterator of a temporary array where we are gonna locate the elements already sorted
    int temp[5]; // -> the temporary array (size should be the same as the original array)

    while(i <= medium && j <= right){ // -> because i (as the left subarray) can only go until the middle, and j (as the right subarray) can only go until the right
        if(arr[i] <= arr[j]){ // -> if the value on index i is lesser than the value on index j 
            temp[k] = arr[i]; // -> in the temp. array we place that element
            i++; // -> iter to the next i index
            k++; // -> iter to the next k index (in the temp array)
            // not to the right one (j), because we are still gonna compare that index (j) with the next index (i++) of this left subarray
        }
        else { // same logic here...
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    // When the (i <= m && j <= right) condition is over, and there's still some values left in either subarrays... (is either one or the other, it cannot be both (that have values left))
    while(i <= medium){
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Replace original array values with the temp array ones
    for(int x = 0; x <= right; x++){
        arr[x] = temp[x];
    }
}

void mergeSortAlgorithm(int arr[], int left, int right){
    if(left < right){  // -> making sure the array wasn't iterated completely
        int medium = (left + right) / 2;  // -> formula to calculate medium

        // Using recursion...
        mergeSortAlgorithm(arr, left, medium);  // -> for the left subarray
        mergeSortAlgorithm(arr, medium + 1, right); // -> for the right subarray

        merge(arr, left, medium, right);  // -> this will perform the process explained in the function above
    }
    /*
    EXPLANATION
    It will divide the whole array first into two halves, then those halves will be divided into two other halves and so on,
    until there are only two or one element in each subarray. (Where left < right will not be true)

    There the sorting will take place and once they are correctly sorted will go 'up' to the previous subarrays
    following the merge() function logic
    */
}

int main(){
    int arr[5] = {9, 7, 3, 6, 2};
    int Nsize = sizeof(arr) / sizeof(arr[0]);

    mergeSortAlgorithm(arr, 0, Nsize - 1);

    cout << "After the sort..." << endl;
    for(int x = 0; x < Nsize; x++){
        cout << arr[x] << " | ";
    }
}
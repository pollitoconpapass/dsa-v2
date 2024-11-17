#include <iostream>

// === Counting Sort Function ===
void countingSort4Radix(int arr[], int sizeOfArr, int div){
    // 1. Create the Output and Count array
    int range = 10;
    int outputArr[sizeOfArr];
    int countArr[range];

    // 2. Fill count array with 0 as well
    for(int i=0; i<range; i++){
        countArr[i] = 0;
    }

    // 3. Increment by one the values of count array based on the least significant digit of each value in original array
    for(int i=0; i<sizeOfArr; i++){
        countArr[ (arr[i]/div)%10 ]++; // -> (arr[i]/div)%10 will return you the least significant digit
        // and at that index we will +1 in countArr (we will be storing the count of the least significant digit)
    }

    // 4. Take each value in the count aray and sum (n + (n-1)) and place it at countArr[n]
    for(int i=1; i<range; i++){
        countArr[i] += countArr[i-1]; // -> the continuous sum (n + (n-1)) of the elements in the count array. 
        // {2, 0, 2, 0, ...} -> {2, 2, 4, 4, ...} 
    }

    // 5. Make the interpretation process
    for(int i=sizeOfArr -1; i>=0; i--){ // -> we will go right to left in the input array (arr)
        outputArr[ countArr[ (arr[i]/div) % 10 ] - 1 ] = arr[i]; // the value of arr[i] is gonna be stored in output arr at...
        // location: countArr[(arr[i]/div)%10]-1 

        countArr[ (arr[i]/div) % 10 ]--; // -> in the count array we less the element, which we interpret as the location index in the outputArr

        /* Example: 
        ### FIRST ITERATION ###
        For the first iteration, we will have the last element of the array: 66 -> arr[i] = 66
        For the first iteration as well, div is 1.  -> div = 1
        (As the least significant digit for the first iteration are the UNITS. For the 2nd will be TENS and for the third HUNDREDS, and so on...)
        
        So (arr[i]/div) = 66 

        Then, it says (arr[i]/div)%10 -> (66)%10 -> is 6 
        That 6 is the index we should look at countArr -> countArr[6] -> 8

        Then, outputArr[countArr[6] - 1] -> [8-1] = 7
        Means we should place at outputArr[7] the value of arr[i] which is 66 -> outputArr[7] = 66


        ### SECOND ITERATION ###
        For the second iteration, we take the element next to the one that was at the end. arr[i] = 2
        ... div is still 1. -> div = 1

        So (arr[i]/div) = (2/1) = 2

        Then it says (arr[i]/div)%10 -> (2%10) -> is 2
        That 2 is the index we should look at count arr -> countArr[2] -> 4

        Then, outputArr[countArr[0] - 1] -> [4-1] = 3
        Means we should place at outputArr[3] the value 2 -> outputArr[3] = 2
        */
    }

    // 6. Return the final and sorted array
    for(int i=0; i<sizeOfArr; i++){
        arr[i] = outputArr[i];
    }
}

// === Function to get the maximum element in an array ===
int getMax(int arr[], int size){
    int max = arr[0];

    for(int i=0; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
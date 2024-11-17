#include <iostream>
using namespace std;

void shellSort(int arr[], int size){
    // 1. Define the gap
    for(int gap=size/2; gap>0; gap/=2){ // -> gap = n/2. Per iteration -> gap = gap / 2

        // Ex: 1st iteration in arr = {66, 2, 24, 90, 170, 75, 802, 45, 7} | gap = 4
        for(int j=gap; j < size; j++){  // -> j = gap = 4    |  is j < size to not pass the array indexes
            int temp = arr[j]; // -> temp = arr[4] = 66 
            int i = 0;

            for(i=j; i>=gap && arr[i-gap]>temp; i-=gap){ // i = 4; 4>=4 && arr[0] = 170 > 66 
                // |-> that arr[i-gap]>temp is making the actual comparison between 2 numbers considering the gap.

                // |-> the i>= gap and i-=gap are necessary for when we make the swap and it is possible to compare 'gap' indexes behind.
                /*EXPLANATION: Suppose we are in the last index (j = 8). 
                    if we make then the i-=gap we will obtain 4 because: 
                    i=j = 8
                    gap = 4

                    So: i - gap = 4, which means i = 4.
                    and 4 IS greater or equal than gap (4 >= 4) TRUE             
                */

                // Continuing with the 1st iteration example...
                arr[i] = arr[i-gap]; // -> here we make the swap.
                // now we are assigning arr[i] (as i = j and j = 4) 
                // to arr[i-gap] (as i = j anf j = 4 and gap = 4), arr[0] = 170 which means...
                // arr[4] = 170

                /*Just for the record, 66 is still stored in temp. 
                and, as i is i = i -gap. i is currently 4, and gap is also 4. 
                So, i - gap =  4 - 4 = 0

                i=0 breaks the condition inside the for loop. (i>=gap) due to i = 0 and gap = 4.
                We exit the loop and...
                */
            }
            arr[i] = temp; // -> ... assign arr[i] (as i is now 0, its the first index) to temp. 
            // REMEMBER: 66 was still stored in temp. WE MADE THE ACTUAL SWAP!


            /*
            Then, for the 2nd iteration of THIS for loop: (int j=gap; j < size; j++)
            j = j + 1 = 4 + 1 = 5 
            j = 5
            gap = 4 (still 4)

            So when we enter the next for loop inside: 
            i = 5 (as i = j)

            Conditions: 
            1. i>=gap TRUE as 5 >= 4 

            2. arr[i-gap]>temp
                - arr[i-gap] = 5 - 4 = arr[1] = 2
                - temp = arr[j] = arr[5] = 75

                AS YOU MAY NOTICED IT... THE COMPARISON GOES AS SAID IN THE THEORY. 
                WITH THIS LOGIC, THE ARRAY IS BEING ITERATED AND COMPARED TAKING INTO CONSIDERATION THE GAP

                NOTICE: (gap is 4)
                First time: arr[i-gap]>temp -> arr[0] > arr[4] 
                Second time: arr[i-gap]>temp -> arr[1] > arr[5]
                ...

            */
        }
    }
}

int main(){
    int arr[9] = {170, 75, 802, 90, 66, 2, 24, 45, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    shellSort(arr, size);

    // After sort:
    cout << "=== SORTED ARRAY===" << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << " | ";
    }
    return 0;
}
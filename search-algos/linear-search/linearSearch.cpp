/*
STEPS 2 FOLLOW:
1. Take input array from user
2. Take element you want to search
3. Start from 1st element in array to last
4. if match found 
        then -> print the number
        stop process
    else
        move to the next element
5. Finish process
*/

#include <iostream>
using namespace std;

void linearSearch(int numbers[], int Nsize, int number2Search){
    int temp = -1; // -> for checking if the number was found or not...

    for (int i= 0; i <= Nsize; i++){
        if (numbers[i] == number2Search){
            temp = numbers[i];
            cout << "Number " << temp << " found at position: " << i << endl;
            break;
        } 
    }

    if (temp == -1){ // -> is only -1 if it's still the same value as initialized
        cout << "Number not found in the array" << endl;
    }
}

int main(){
    int num2Search; 
    int arr[5] = {1, 22, 34, 5, 7};
    int Nsize = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter number to search: "; cin >> num2Search;

    linearSearch(arr, Nsize, num2Search);
    return 0;
}

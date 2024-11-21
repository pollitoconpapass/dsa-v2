// Create a stack that supports:
// - push()
// - pop()
// - getMin() - returns minimum element in O(1) time

#include <iostream>
using namespace std;

class MinStack {
private:
    int top;
    int arr[5];
public:
    // Constructor
    MinStack() {
        top = -1; // Initializing it empty ...
        // for (int i = 0; i < 5; i++) {
        //     arr[i] = 0; // ... and with all zeros.
        // }
    }

    // === Check if it's empty ===
    bool isEmpty(){
        if(top== -1){
            return true;
        } else{
            return false;
        }
    }

    // === Check if it's full ===
    bool isFull(){
        if(top == 4){
            return true;
        } else {
            return false;
        }
    }

    // === Add new element ===
    void push(int x){
        if(isFull()){
            cout << "Stack overflowed..." << endl;
        }

        top++;
        arr[top] = x;
    }

    // === Delete an element ===
    void pop(){
        if(isEmpty()){
            cout << "Can't delete anything because the stack is empty." << endl;
        }
        cout << "Deleting last element: " << arr[top] << endl;
        arr[top] = 0;
        top--;
    }

    // === Get the minimum element of the stack ===
    int getMin(){
        if(this->top == -1){ // -> if it's empty
            return -1;
        }

        // Do the actual search for the minimum
        int min = arr[0];

        for(int i=0; i<5; i++){
            if(arr[i] < min && arr[i] != 0){
                min = arr[i];
            }
        }

        return min;
    }
};


int main(){
    int opt, value, minElement;
    MinStack minstack;

    do {
        cout << "\nOptions" << endl;
        cout << "1. Push an element to the stack" << endl;
        cout << "2. Pop an element from the stack" << endl;
        cout << "3. Find the minimum element in the stack" << endl;
        cout << "Enter your option: "; cin >> opt;

        switch(opt){
            case 1:
                cout << "Enter the element to push: "; cin >> value;
                minstack.push(value);
                break;
            
            case 2:
                minstack.pop();
                break;
            case 3:
                minElement = minstack.getMin();
                if(minElement == -1){
                    cout << "The stack is empty..." << endl;
                } else {
                    cout << "The minimum element of the stack is " << minElement << endl;
                }
                break;
            default:
                cout << "Enter a valid option..." << endl;
                break;
        }

    } while(opt != 0 || opt > 3);
}
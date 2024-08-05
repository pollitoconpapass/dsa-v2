#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
  int top;
  int arr[5];

public:
  // Constructor
  Stack() {
    top = -1; // Initializing it empty ...
    for (int i = 0; i < 5; i++) {
      arr[i] = 0; // ... and with all zeros.
    }
  }

  // STACK METHODS
  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }

  bool isFull() {
    if (top == 4)
      return true;
    else
      return false;
  }

  void push(int val) {
    if (isFull()) // -> if it's already full, we cannot add more
      cout << "Stack Overflowed" << endl;

    else {
      top++;          // -> top becomes 0 or higher
      arr[top] = val; // now top adopts the value we're passing
    }
  }

  int pop() {
    if (isEmpty()) { // -> if it's already empty, we cannot remove anything
      cout << "The stack is empty" << endl;
      return 0;
    }

    else {
      int popValue = arr[top]; // -> the value we're popping is the last entered
      arr[top] = 0; // we make the top value 0 as its gonna be removed
      top--;        // decrement the top
      return popValue;
    }
  }

  int count() {
    return (top + 1); // -> as in programing we start counting from 0...
  }

  int peek(int position){
    if (isEmpty()) {
      cout << "The stack is empty" << endl;
      return 0;
    }
    else
      return arr[position]; // -> return the value at that position
  }

  void change(int position, int value){ // -> we will need the value and the position where to change the value
    arr[position] = value; // -> performing the actual change
    cout << "Value changed at location " << position << endl;
  }

  void display(){
    cout << "All values in the stack are: " << endl;
    for (int i = 4; i >= 0; i--) // -> loop through the whole stack in desc. order
      cout << arr[i] << endl; // show it in console
  }


};

void Menu(){
  Stack s1;
  int option, position, value;

  do{
    // === MAIN MENU ===
    cout << "\nWHAT OPERATION WOULD YOU LIKE TO PERFORM?" << endl;
    cout << "1. Add a value" << endl;
    cout << "2. Remove a value" << endl;
    cout << "3. Check if it's empty" << endl;
    cout << "4. Check if it's full" << endl;
    cout << "5. Access to one specific value" << endl;
    cout << "6. Know the length" << endl;
    cout << "7. Change a valueat x position" << endl;
    cout << "8. Display the stack" << endl;

    // === DIFFERENT OPTIONS ===
    cin >> option;
    cout <<"\n";
    switch(option){
      // push()
      case 1:
        cout << "Enter the number to add: "; 
        cin >> value;
        s1.push(value);
        break;
      // pop()
      case 2: 
        cout << "The value removed is " << s1.pop() << endl;
        break;
      // isEmpty()
      case 3:
        if(s1.isEmpty()) 
          cout << "The stack is indeed empty" << endl;
        else
          cout << "The stack is not empty" << endl;
        break;
      // isFull()
      case 4:
        if(s1.isFull())
          cout << "The stack is indeed full" << endl;
        else 
          cout << "The stack is not full" << endl;
        break;
      // peek()
      case 5:
        cout << "Enter the position you want to consult";
        cin >> position;

        cout << "The value at that position is " << s1.peek(position) << endl;
        break;
      // count()
      case 6:
        cout << "The length of the stack is " << s1.count() << endl;
        break;
      // change()
      case 7:
        cout << "Enter the position you want to change: ";
        cin >> position;
        cout << "What's the new value: ";
        cin >> value;

        s1.change(position, value);
        cout << "The change was done successfully";
        break;
      // display()
      case 8:
        s1.display();
        break;

      default:
        cout << "Enter proper option number" << endl;

    }

  } while(option <= 0 || option > 8);
}


int main() { 
  Menu();
  return 0;
}
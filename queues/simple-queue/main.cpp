#include <iostream>
using namespace std;

class Queue{
private:
  int front;
  int rear;
  int arr[5];

public:
  Queue(){
    front = -1;  // -> now there is front and rear becaue there is
    rear = -1;  // -> one exit and one entrance
    for (int i=0; i<5; i++){
      arr[i] = 0;
    }
  }

  bool isEmpty(){
    if (front == -1 && rear == -1) // if they are the same value as beginn.
      return true;
    else
      return false;
  }

  bool isFull(){
    if (rear == sizeof(arr) -1) 
      /* 
      when a new value is introduced, the rear value will increment.
      If I insert one value, rear will be 0, if I add two values, rear will be 1, 
      and so on...
      That's why if the queue is full and the size is 5), then the rear is gonna 
      be 4. size(arr) -1 is the last index.
      */
      return true;
    else
      return false;
  }

  void enqueue(int val){
    if (isFull()){
      cout << "Queue is full" << endl;
      return;
    }
    else if (isEmpty()) { // -> when adding thr first value
      rear = front = 0; // -> we make the rear and front 0, to increase it
      // (we can't use rear++, cause the original value is negative)
      arr[rear] = val; // -> we add the value
    }
    else { // -> when there are some values in the queue and it's not full
      rear++; // -> increment a next index (adding a new space)
      arr[rear] = val; // -> add the value
    }
  
  }

  int dequeue(){
    int x;  // -> to store the value (the one in front)
    
    if(isEmpty()){
      cout << "Queue is empty" << endl;
      return 0;
    }
    else if (front == rear) { // when there's only one value in the queue
      x = arr[front]; // -> we save the value
      arr[front] = 0; // -> change the value to 0 as it's gonna be deleted
      rear = front = -1; // -> like a start-again (reset to -1 as the beginn.)
      return x; // -> return the value previuosly saved
    }
    else { // when there are several values in the queue
      x = arr[front]; // -> save the value 
      arr[front] = 0; // -> change the value to 0 as it's gonna be deleted
      front++; // -> change the front to the next value
      return x;  // -> return the value previously saved
    }
  }

  int count(){
    if (isEmpty()){
      return 0;
    }
    return (rear-front+1);
    /*
    Suppose we have this queue:
      | 6 | 5 | x | x | x |      -> x means there's no value in there
      where front = 0 and rear = 1 (as all of them start in -1 REMEMBER!!) 
      (rear - front + 1) = (1 - 0 +1) = 2 -> the actual n of values in the queue
    */
  }

  void display(){
    for (int i=0; i<5; i++)
      cout << arr[i] << endl;
  }
};

void Menu(){
  int option, value;
  Queue q;

  do{
    cout << "\nEnter the option you want to perform: " << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Check if it's full" << endl;
    cout << "4. Check if it's empty" << endl;
    cout << "5. Count the elements in the queue" << endl;
    cout << "6. Display the queue" << endl;

    cout << "\nOption: ";
    cin >> option;
    cout << "\n" ;

    // CASE OPTIONS
    switch (option){
      // enqueue()
      case 1:
        cout << "Enter the value you want to enqueue: ";
        cin >> value;
        q.enqueue(value);
        break;
      // dequeue()
      case 2:
        cout << "The value dequeued is: " << q.dequeue() << endl;
        break;
      // IsFull()
      case 3:
        if(q.isFull())
          cout << "The queue is indeed full" << endl;
        else
          cout << "The queue is not full"<< endl;
        break;
      // IsEmpty()
      case 4:
        if(q.isEmpty())
          cout << "The queue is indeed empty" << endl;
        else
          cout << "The queue is not empty"<< endl;
        break;
      // count()
      case 5:
        cout << "The queue has " << q.count() << " elements" << endl;
        break;
      // display()
      case 6:
        q.display();
        break;
    }
  } while (option != 0 || option > 6);
}

int main() {
  Menu();
  return 0;
}

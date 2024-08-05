// THE REAL DEAL STARTS IN LINE 31

#include <iostream>
using namespace std;

class CircularQueue{
private:
  int front;
  int rear;
  int arr[5];
  int itemCount;
  int Nsize = sizeof(arr) / sizeof(arr[0]);

public:
  CircularQueue(){
    itemCount = 0;
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
    if ((rear+1)%Nsize == front) 
      /* 
      when the queue is full, and we haven't dequeued any value, then:
      - rear = 4
      - front = 0 (because it's the first value, and we haven't dequeued)

      So...
      (rear+1)%Nsize == front
      (4+1)%5==0 -> 5%5 == 0 -> 0 == 0
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
    else if (isEmpty()) { // -> when adding the first value
      rear = front = 0; // -> we make the rear and front 0, to increase it
      // (we can't use rear++, cause the original value is negative)
      arr[rear] = val; // -> we add the value
    }
    else { // -> when there are some values in the queue and it's not full
      // rear++; // -> increment a next index (adding a new space)

      // === FOR CIRCULAR QUEUE ===
      rear = (rear + 1)%Nsize; // the residual of dividing the size of the array by the (rear value + 1)
      arr[rear] = val; // -> add the value
      /*
      When you first enqueue a value, it will execute the conditin above. 
      Then, when there's only one value inside, the rear will be equal to zero and this condition will be something like this: 
      rear = (0 + 1)%5 = 1  (with just one value)
      and so on...
      rear = (1 + 1)%5 = 2  (with 2 values)
      rear = (2 + 1)%5 = 3  (with 3 values)
      rear = (3 + 1)%5 = 4  (with 4 values)

      ... but when it's already full:
      rear = (4 + 1)%5 = 0  (with 5 values, as the size of the array is 5)

      rear will be 0. Getting back as when the queue just had one value.
      */
      
    }
    itemCount++;
  }

  int dequeue(){
    int x = 0;  // -> to store the value (the one in front)

    if(isEmpty()){
      cout << "Queue is empty" << endl;
      return x;
    }
    else if (front == rear) { // when there's only one value in the queue
      x = arr[front]; // -> we save the value
      arr[front] = 0; // -> change the value to 0 as it's gonna be deleted
      rear = front = -1; // -> like a start-again (reset to -1 as the beginn.)
      itemCount--;
      return x; // -> return the value previously saved
    }
    else { // when there are several values in the queue
      x = arr[front]; // -> save the value 
      arr[front] = 0; // -> change the value to 0 as it's gonna be deleted
      // front++; // -> change the front to the next value

      // === FOR CIRCULAR QUEUE ===
      front = (front+1)%Nsize; // -> it will have the same functionality as rear in enqueue()
      itemCount--;
      return x;  // -> return the value previously saved
    }
  }

  int count(){
    return itemCount;
  }

  void display(){
    for (int i=0; i<5; i++)
      cout << arr[i] << endl;
  }
};

void Menu(){
  int option, value;
  CircularQueue q;

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

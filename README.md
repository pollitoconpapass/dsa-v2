# Data Structures and Algorithms in C++ Programming Language

Here will be recopiled all the theory and examples of the different Data Structures. 
From Stacks to Graphs.

Meanwhile, here's a cheatsheet to remember C++ basics...

## Hello World
```cpp
#include <iostream>
using namespace std;

int main(){
    cout << "Hello World";
    return 0;
}
```

## Variables
```cpp
string name = "Bjarne";
int year = 1979;
bool madeIt = true;
```

## User Input 
```cpp
int main(){
    string name;
    cout << "Enter your name: " ;
    cin >> name;
    
    return 0;
}
```

## Conditionals
```cpp
if (number == 4){
    cout << "Number is the result of 2 x 2" << endl;
}
else if (number == 5){
    cout << "Number is the result of 25/5" << endl;
}
else{
    cout << "The number is not 4 or 5" << endl;
}
```
    
* Conditional Operators 

    - and --> `&&`
    - or --> `||`
    - less than --> `<`
    - more than --> `>`
    - less equal than --> `<=`
    - more equal than --> `>=`

## While Loop
```cpp
while(option == 3){
    // some code...
}
```


## Do-While Loop
```cpp
do {
    // some other code...
} while(option != 0 || option > 8);
```

## For Loop
```cpp
for(int i = 0; i < 5; i++){
    cout << i << endl;
}
```

## Arrays
* Simple ones
```cpp
int arr[5] = {3, 4, 5, 6, 7};
```

* With pointers
```cpp
int* vector;
vector = new int[11];
```
    
    
## 2D Arrays
* Simple ones 
```cpp
int matrix[44]; // 44 rows
for(int i=0; i<44; i++){
    matrix[i] = int[20]; // 20 columns 
}
```

* With pointers
```cpp
int** matrix;
matrix = new int[44]; // ->  44 rows
for(int i = 0; i < 44; i++){
    matrix[i] = new int[20]; // 20 columns
}
```

## Structs
```cpp
typedef struct {
    int age;
    float salary;
} person; // -> alias of the struct
```

* To instance
```cpp
person* alex;
alex = new person;

// Assign values
alex.age = 20;
alex.salary = 2500.50;
```

## Functions
```cpp
int add(int a, int b){
    return a + b;
}

void greeting(string name){
    cout << "Hello "  << name << endl;
}
```

## OOP Basic Structure
```cpp
class Person{
    private:
        // ATRIBUTES
        string name;
        int age;
        
    public:
        // CONSTRUCTOR
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }
        
        // DESTRUCTOR
        ~Person(){}
        
        // === METHODS ===
        void Greet(){
            cout << "Hey, my name is " << name << "and I am " << age << "years old!" << endl;
        }
        
        int AgeIn5Years(){
            return age + 5;
        }
        
        // === GETTERS ===
        string get_name(){
            return name;
        }
        
        int get_age(){
            return age;
        }
        
        // === SETTERS ===
        void set_name(string value){
            this->name = value;
        }
        
        void set_age(int value){
            this->age = value
        }
};
```
    
    
## Declare an object
* Normal
```cpp
Person female1;
female1.name = "Mia";
female1.age = 28;
```   

* As a pointer
```cpp
Persona* male2;
male2 = new Persona("John", 30);
```


## Inheritance
```cpp
class Dog : public Pet{
    private:
        // Atributes...
    
};
```


## Polymorphism
```cpp
virtual void Show(){
    cout << "This is Polymorphism" << endl;
}

// In the other class:
void Show(){
    Cat::Show();
    cout << "... and this is how it works" << endl;
}
```

## Other Concepts to Take into Consideration
- Clean the screen
```cpp
system("cls");
```

- Get the size of an Array:
```cpp
int size = sizeof(arr)/sizeof(arr[0]);
```

- Get the complete string of the user's input (including spaces):
```cpp
string word;
cout << "Enter a word: ";
getline(cin, word);
```

- C++ 11 Iterate way (new version)
```cpp
for(int i: arr){
    cout << i << endl;
}
```
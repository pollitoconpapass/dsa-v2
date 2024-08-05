# Data Structures and Algorithms in C++ Programming Language

Here will be recopiled all the theory and examples of the different Data Structures. 
From Stacks to Graphs.

Meanwhile, here's a cheatsheet to remember C++ basics...

## Hello World

    #include <iostream>
    using namespace std;
    
    int main(){
        cout << "Hello World";
        return 0;
    }


## Variables
    string name = "Bjarne";
    int year = 1979;
    bool madeIt = true;


## User Input 
    int main(){
        string name;
        cout << "Enter your name: " ;
        cin >> name;
        
        return 0;
    }


## Conditionals
    if (number == 4){
        cout << "Number is the result of 2 x 2" << endl;
    }
    else if (number == 5){
        cout << "Number is the result of 25/5" << endl;
    }
    else{
        cout << "The number is not 4 or 5" << endl;
    }
    
* Conditional Operators 

        and --> &&
        or --> ||
        less than --> <
        more than --> >
        less equal than --> <=
        more equal than --> >=

## While Loop
    while(option == 3){
        // some code...
    }


## Do-While Loop
    do {
        // some other code...
    } while(option != 0 || option > 8);


## For Loop
    for(int i = 0; i < 5; i++){
        cout << i << endl;
    }


## Arrays
* Simple ones

        int arr[5] = {3, 4, 5, 6, 7};

* With pointers

        int* vector;
        vector = new int[11];
    
    
## 2D Arrays
* Simple ones 

        int matrix[44]; // 44 rows
        for(int i=0; i<44; i++){
            matrix[i] = int[20]; // 20 columns 
        }

* With pointers

        int** matrix;
        matrix = new int[44]; // ->  44 rows
        for(int i = 0; i < 44; i++){
            matrix[i] = new int[20]; // 20 columns
        }


## Structs
    typedef struct {
        int age;
        float salary;
    } person; // -> alias of the struct

* To instance

        person* alex;
        alex = new person;
        
        // Assign values
        alex.age = 20;
        alex.salary = 2500.50;


## Functions
    int add(int a, int b){
        return a + b;
    }
    
    void greeting(string name){
        cout << "Hello "  << name << endl;
    }

## OOP Basic Structure
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
    
    
## Declare an object
* Normal

        Person female1;
        female1.name = "Mia";
        female1.age = 28;
        
* As a pointer

        Persona* male2;
        male2 = new Persona("John", 30);
        


## Inheritance
    class Dog : public Pet{
        private:
            // Atributes...
        
    };


## Polymorphism
    virtual void Show(){
        cout << "This is Polymorphism" << endl;
    }
    
    // In the other class:
    void Show(){
        Cat::Show();
        cout << "... and this is how it works" << endl;
    }





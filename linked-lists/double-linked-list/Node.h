#include <iostream>

class Node{
public:
    int key;
    int data;
    Node *next;
    Node *previous;

    // Constructor 
    Node(){
        this->key = 0;
        this->data = 0;
        this->next = NULL;
        this->previous = NULL;
    }

    Node(int key, int data){
        this->key = key;
        this->data = data;
    }

};
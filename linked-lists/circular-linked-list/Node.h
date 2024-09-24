#include <iostream>

class Node{ 
public:
    int key;
    int data;
    Node *next;

    Node(){
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int key, int data){
        this->key = key;
        this->data = data;
    }
};
#include <iostream>

class Node{
public:
    int key;
    int data;
    Node* next;

    Node(){
        key=0;
        data=0;
        next=NULL;
    }

    Node(int k, int d){
        this->key = k;
        this->data = d;
    }
};
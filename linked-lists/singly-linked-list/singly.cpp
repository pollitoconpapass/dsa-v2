#include <iostream>
#include "Node.h"
using namespace std;

class SinglyLinkedList{
public:
    Node* head;

    SinglyLinkedList(){
        head=NULL;
    }

    SinglyLinkedList(Node *n){
        head = n;
    }

    // === METHODS ===

    //1. Check if a Node already exists using key value
    Node *nodeExists(int key){
        Node *temp = NULL; // -> first create an auxiliar value.
        Node *ptr = head; // -> a pointer is created and initialized to the head

        while (ptr != NULL){  // -> if the memory address is not NULL (if the list is not empty)
            if (ptr->key == key){  // -> until the key is the same as one already there...
                temp = ptr;  // -> // the auxiliar address will be the same as the ptr address
            }

            ptr = ptr->next; // -> go over the next address memory and restart the checking.
        }

        return temp; // -> return the auxiliar that has the 'repeated' address memory
    }

    // 2. Append Node (to the end)
    void appendNode(Node *n){
        if(nodeExists(n->key) != NULL){ // -> if the node does exists (if it doesn't it should return NULL as it is initialized, review above...)
            cout << "Node already exists with key: " << n->key << endl;
            cout << "Append another node with different key value.." << endl;
        }
        else{ // the node doesn't exist in the list yet
            if(head==NULL){ // -> if the list is empty (it will have the default value)
                head = n; // -> the address of head will be now of the new node
                cout << "Node appended" << endl;
            }
            else{ // when there's already data inside the list
                Node *ptr = head; // -> take the address of the head and store it inside another pointer

                while(ptr->next != NULL){ // while the next address pointer is not NULL...
                    ptr = ptr->next;  // -> pass to the next pointer one and so on until reaching the one at last (which is not gonna be pointing to any next value... cause there's no next)
                }
                ptr->next = n; // -> when finally reachin the last value... make the next pointer point to the new node adress' passed as argument
                cout << "Node Appended!" << endl;
            }
        }
    }

    // 3. Prepend Node (at the start)
    void prependNode(Node *n){
        if(nodeExists(n->key) != NULL){ // -> if the node does exists (if it doesn't it should return NULL as it is initialized, review above...)
            cout << "Node already exists with key: " << n->key << endl;
            cout << "Append another node with different key value.." << endl;
        }
        else{
            n->next = head; // -> the next pointer of the new node is going to have the head's address (like a way of connecting the new node to what was the head of the list)
            head = n; // -> now swap the head to this new node address.
            cout << "Node prepended" << endl;
        }
    }

    // 4. Insert a Node after a particular node in the list.
    void insertNodeAfter(int key, Node *n){
        Node *ptr = nodeExists(key); // -> it basically does the same as the previous ifs to check if the key already exists, 
            // but this time we have to access it to insert a new node after that particular node with that key

        if (ptr == NULL){ // if the address memory is NULL means that the key is not in the list, so we cannot insert anything.
            cout << "No node exists with key value " << key << endl;
        }
        else {
            if(nodeExists(n->key) != NULL){  // -> Here we will check if the key of the node we are gonna insert already exists
            // REMEMBER: key to insert after (location) != key of the new node to insert (key of the new node)
                cout << "Node already exists with key: " << n->key << endl;
                cout << "Append another node with different key value..." << endl;
            }
            else {
                n->next = ptr->next; // -> the next pointer of the new node has to have or 'point to' the same address as the next pointer of ptr 
                // Cause right now, ptr is storing the address of the node which key we passed as argument and has found it (review the nodeExists function)
                // ... so the address the next pointer of the new node is gonna be the same address of that the next node of ptr has (which is the next element in the list), creating a link between them

                // ptr->next and n->next have the same address value...
                ptr->next=n; // -> now the next node of ptr must change to 'point to' the address memory of the new node
                cout << "Node Inserted!" << endl;
            }
        }
    }

    // 5. Delete a Node by key
    void deleteNodeByKey(int key){
        if(head == NULL){ // -> check if it is empty first.
            cout << "Singly Linked List already empty. Can't delete anything." << endl;
        }
        else if (head != NULL){ // if it has values...
            if (head->key == key){ // -> check if it's the first element of the list
                head = head->next;  // -> then the head address must change to the of the next node adresss
                cout << "Node UNLINKED with key value " << key << endl;
            }
            else{
                Node *temp = NULL; // -> creating a temporal node
                Node *prevptr = head;  // -> a new pointer that will point to the head address
                Node *currentptr = head->next;  // -> currentptr will point to the address the node next to head, the 2 one in order

                while (currentptr != NULL){  // -> only if the address in currentptr has data, we will move forward
                    if (currentptr->key == key){  // if the key of currentptr is the same as the key of the node you want to delete...
                        temp = currentptr; // -> temp will have the address of that node
                        currentptr = NULL;  // -> as we find the key we want to delete, we make currentptr NULL to stop the while loop
                    }
                    else {  // -> but if we haven't found it yet...
                        prevptr = prevptr->next;  // -> prevptr pass to the next one
                        currentptr = currentptr->next;  // -> so does currentptr
                    }
                }

                if (temp != NULL){ // if we found the key, then temp will be assigned to the address memmory of the node to delete, so it will not be NULL
                    prevptr->next = temp->next; // -> the prevptr pointer  (which is the previous in order of the one we want to delete)...
                                            // ... will point now to the address of the temp pointer
                                            // ... as temp contains the address of the node to delete 
                    cout << "Node UNLINKED with key " << key << endl;
                }
                else{
                    cout << "Node with key " << key << " does not exists" << endl;
                }
            }
        }
    }

    // 6. Update Node by key
    void updateNodeByKey(int key, int newData){
        Node *ptr = nodeExists(key); // -> you will recive the address memory of the node you want to update

        if (ptr != NULL){ // -> if it's not NULL, means it exists...
            ptr->data = newData;  // -> update the data
            cout << "Node with key " << key << "updated successfully!" << endl;
        }
        else{
            cout << "No node found with key" << key << endl;
        }
    }

    // 7. Show the Linked List
    void showMeShowMe(){
        if (head == NULL){
            cout << "No Nodes entered yet." << endl;
        }
        else {
            cout << endl << "Singly Linked List: " << endl;
            Node *temp = head;  // -> a temp will go through all the list starting from the head

            while(temp!= NULL){
                cout << "(" << temp->key << "|" << temp->data << ")--> ";  // -> prints out the key and the value in each node
                temp = temp->next; // -> goes through the list
            }
            cout << endl;
        }
    }

    // 8. Reverse the linked list
    void reverseLinkedList(){
        if (head == NULL){
            cout << "The list is empty. Cannot reverse." << endl;
        }
        else {
            Node *prev = NULL;
            Node *current = head;
            Node *nextNode = NULL;

            while (current != NULL){
                nextNode = current->next; // -> nextNode will have the address of the next node of the head
                current->next = prev;  // -> the next node of current will be assigned to prev (the previous node -> will be NULL initially)
                prev = current; // -> prev takes the address of the current node
                current = nextNode; // -> current will be now nextNode, (that had the next node of the current one)
            }

            // The process is gonna repeat changing the next pointer of each current node to the previous node (actually reversing the list)

            head = prev; // -> prev will be iterating until the last element... we make the last element now the head (we're reversing)
            cout << "List reversed successfully" << endl;
        }
    }
};


void Menu(){
    SinglyLinkedList linkedList;
    int option;
    int data;
    int key, keyAfter; // -> keyAfter is for the insertAfterNode()

    do {
        cout << "\nChoose an option" << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertAfterNode()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. showLinkedList()" << endl;
        cout << "7. reverseLinkedList()" << endl;
        cout << "8. Clear the Screen" << endl;

        cout << "Option: " ; 
        cin >> option;


        Node* node1 = new Node(); // -> node where the data and key the user inputs are gonna be stored

        switch(option){
            case 1:
                cout << "Enter the values of the new node to append..." << endl;
                cout << "Key: "; cin >> key;
                cout << "Data: "; cin >> data;

                node1->data = data;
                node1->key = key;

                linkedList.appendNode(node1);
                break;

            case 2: 
                cout << "Enter the values of the new node to prepend..." << endl;
                cout << "Key: "; cin >> key;
                cout << "Data: "; cin >> data;
                
                node1->data = data;
                node1->key = key;

                linkedList.prependNode(node1);
                break;

            case 3: 
                cout << "Enter the respective values to insert the data after a key: " << endl;
                cout << "Key to insert after: "; cin >> keyAfter;
                cout << "Enter the key of the new node: "; cin >> key;
                cout << "Value of the new node: "; cin >> data;

                node1->data = data;
                node1->key = key;

                linkedList.insertNodeAfter(keyAfter, node1);
                break;

            case 4:
                cout << "Enter data to delete the Node..." << endl;
                cout << "Key: "; cin >> key;

                linkedList.deleteNodeByKey(key);
                break;

            case 5:
                cout << "Enter data to update Node by key..." << endl;
                cout << "Key of the node to update: "; cin >> key;
                cout << "Data of the node to update: "; cin >> data;

                linkedList.updateNodeByKey(key, data);
                break;

            case 6:
                linkedList.showMeShowMe();
                break;

            case 7: 
                linkedList.reverseLinkedList();
                break;

            case 8: 
                system("cls");
                break;

            default:
                cout << "\nInvalid Option"<< endl;
                break;

        }

    } while (option <= 8 || option >= 1);
}

int main(){
    Menu();
    return 0;
}
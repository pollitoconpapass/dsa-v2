#include <iostream>
#include "Node.h"
using namespace std;

class DoubleLinkedList{
public:
    Node *head;

    // === CONSTRUCTORS ===
    DoubleLinkedList(){
        this->head = NULL;
    }
    DoubleLinkedList(Node *n){
        this->head = n;
    }

    // === METHODS ===

    // 1. Check if the node exists using its key value
    Node *checkNodeExists(int key){ // -> the same as in the Single Linked list...
        Node *temp = NULL;
        Node *ptr = head;  // -> initialize ptr with the same address value as the head node

        while(ptr != NULL){ 
            if (ptr->key == key){  // -> when we find that the ptr key is the same as the key we pass as argument,
                temp = ptr;  // -> we keep that node inside temp
            }
            ptr = ptr->next;  // -> if not, we keep iterating through the whole linked list
        }
        return temp;
    }

    // 2. Append a node to the list (at the end of the whole list)
    void appendNode(Node *n){
        if (checkNodeExists(n->key) != NULL){
            cout << "Node with value " << n->key << " already exists. Please append another node with different key value" << endl;
        }
        else {
            if (head == NULL){ // -> if it's the first element to append
                head = n;  // -> just assign head to the node we are passing as argument
                cout << "Node appended as head node successfully" << endl;
            }
            else{
                Node *ptr = head;

                while(ptr->next != NULL){ // -> while the next pointer of ptr is not null, meaning is not the last element...
                    ptr = ptr->next;  // -> continue iterating over the list
                }

                ptr->next = n;  // -> the next pointer will store the address of n (n = the node passed as argument)
                n->previous = ptr; // -> the previous pointer of n will store the address of ptr, which WAS the last node at that moment
                cout << "Node appended successfully" << endl;
            }
        }
    }

    // 3. Prepend Node to the linked list (at the beginning of the whole list)
    void prependNode(Node *n){
        if(checkNodeExists(n->key)!= NULL){
            cout << "Node with that key already exists. Please prepend another node with another key value" << endl;
        }
        else {
            if(head == NULL){  // -> if it's the first value ever to introduce to the list
                head = n; // -> assign the head address to the new node's
                cout << "Node prepended as head Node" << endl;
            }
            else {
                head->previous=n; // -> the previous pointer of the (at that moment) head node will now point to n address
                n->next = head;  // -> the next pointer of the new node will point to the (at that moment) head node address, making the connection
                head = n;  // -> change the head address to the new node

                cout << "Node prepended successfully!" << endl;
            }
        }
    }

    // 4. Insert a Node after a particular node in the list
    void insertNodeAfter(int key, Node *n){
        Node *ptr = checkNodeExists(key);  // -> look for that particular key node

        if(ptr == NULL){ // -> check if the particular key where we want to place the new node after exists or not
            cout << "The node with key " << key << " does not exists" << endl;
        }
        else {
            if(checkNodeExists(n->key) != NULL){  // -> here we check the key of the new node to insert. NOT the key value of an the location where we wnat to insert a new node...
                                                // so it doesn't have to exist
                cout << "Node with the key of the new node: " << n->key << " already exists." << endl;
            }
            else{
                cout << "INSERTING..." << endl;
                Node *nextNode = ptr->next; // -> nextNode will have the memory address of the next pointer of ptr (REMEMBER: ptr is the node where we want to insert the node after)

                // inserting at the end of the list
                if (nextNode == NULL){  // -> if nextNode is NULL, means it ptr is the last element of the list...
                    ptr->next = n; // -> ptr holds the address where we want to insert the new node after, so we assign its next pointer to the address of the new node
                    n->previous = ptr;  // -> we make the previous pointer of the new node to point to the ptr address. 

                    cout << "Node inserted at the end successfully" << endl;
                }

                // inserting in between
                else{
                    n->next = nextNode; // -> the next pointer of the new node will have the address of nextNode... due to that nextNode has the address of the next pointer of ptr. (REMEMBER: ptr is the node where we want to insert the node after)
                    nextNode->previous = n; // -> previous pointer of nextNode will point now to the address of the new node (it will complete the two pointers, next and previous, linked to the new node and the what WAS the next node of the ptr) REMEMBER WHAT ptr IS!! 
                    n->previous = ptr; // -> now the previous pointer of the new node will point to ptr address creating a link between the new node and the ptr
                    ptr->next = n;  // -> the next pointer of ptr, will have the address of the new node. (This completes the whole insertion)

                    cout << "Node inserted in between successfully" << endl;
                }
            }
        }
    }

    // 5. Delete a Node
    void deleteNodeByKey(int key){
        Node *ptr = checkNodeExists(key); // -> this will be the node that has that key value

        if (ptr == NULL){ // -> it doesn't exists
            cout << "No node exists with the key " << key << endl;
        }
        else {
            if (head == NULL){  // -> the list is empty
                cout << "Double Linked List already empty. Can't delete" << endl;
            }
            else if (head != NULL){
                if (head->key == key){ // -> if the Node to delete is the head Node
                    Node *tempDelete = head; // -> assign a temporal to the head address
                    head = head->next;  // -> assign the head address to the next node of what WAS the head
                    delete tempDelete; // -> actually delete the Node

                    cout << "Node unlinked with key " << key << endl;
                }
                else {
                    Node *nextNode = ptr->next; // -> next node of the Node to delete
                    Node *prevNode = ptr->previous;  // -> previous node of the Node to delete

                    // deleting at the end
                    if (nextNode == NULL){ // -> if the nextNode address is NULL, means that ptr is the last element
                        prevNode->next == NULL; // -> just make NULL the prevNode (prevNode is the previous node of ptr, the Node to delete)
                    }
                    
                    // deleting in between
                    else {
                        prevNode->next = nextNode;  // -> the prevNode next pointer will now store the address of the nextNode, skipping completely the address of ptr (the node to delete)
                        nextNode->previous = prevNode;  // -> the nextNode previous will store now the address of the prevNode, skipping as well ptr adress

                        cout << "Node deleted in between successfully." << endl;
                    }
                }
            }
        }
    }

    // 6. Update Node 
    void updateNode(int key, int newData){
        Node *ptr = checkNodeExists(key);

        if (ptr == NULL){
            cout << "The Node with the key " << key << "does not exist. " << endl;
        }
        else {
            ptr->data = newData;
        }
    }

    // 7. Print the Double Linked List
    void showDoubleLinkedList(){
        if (head == NULL){
            cout << "There is no data inside the list :(" << endl;
        }
        else {
            cout << "Double Linked List: " << endl;
            Node *temp = head;

            while (temp != NULL){
                cout << "(" << temp->key << " | " << temp->data <<  ") <--> ";
                temp = temp->next;
            }
        }
    }
};

void Menu(){
    DoubleLinkedList doubleLinkedList;

    int option;
    int key, key2Insert;
    int data;

    // Actual menu
    do {
        cout << "\nSelect an option: "  << endl;
        cout << "1. Append a new node" << endl;
        cout << "2. Prepend a new node" << endl;
        cout << "3. Insert a Node after a key" << endl;
        cout << "4. Delete a Node" << endl;
        cout << "5. Update a Node" << endl;
        cout << "6. Print the double linked list" << endl;
        cout << "7. Clear the screen" << endl;

        cout << "Enter your option: "; cin >> option;
        Node *node = new Node(); // -> idk why but... apparently when I initialize it here, it works correclty :)


        // === SWITCH STATEMENT ===
        switch (option)
        {
        case 1:
            cout << "Enter the respective values to append a new Node..." << endl;
            cout << "Key: "; cin >> key;
            cout << "Data: "; cin >> data;

            node->data = data;
            node->key = key;

            doubleLinkedList.appendNode(node);
            break;

        case 2: 
            cout << "Enter the respective values to prepend a new Node... " << endl;
            cout << "Key: "; cin >> key;
            cout << "Data: "; cin >> data;

            node->data = data;
            node->key = key;

            doubleLinkedList.prependNode(node);
            break;

        case 3: 
            cout << "Enter the respective values to insert a new node after a key... " << endl;
            cout << "Key to insert after: "; cin >> key2Insert;
            cout << "Key of the new node: "; cin >> key;
            cout << "Data of the new node: "; cin >> data;

            node->data = data;
            node->key = key;

            doubleLinkedList.insertNodeAfter(key2Insert, node);
            break;

        case 4: 
            cout << "Enter the respective values to delete a Node..." << endl;
            cout << "Key of the node to delete: "; cin >> key;

            doubleLinkedList.deleteNodeByKey(key);
            break;

        case 5:
            cout << "Enter the respective values to update a Node..." << endl;
            cout << "Key of the Node to update: "; cin >> key;
            cout << "New data of the Node: "; cin >> data;

            doubleLinkedList.updateNode(key, data);
            break;

        case 6: 
            cout << endl;
            doubleLinkedList.showDoubleLinkedList();
            cout << endl;

            break;

        case 7:
            system("cls");
            break;
        
        default:
            cout << "Enter a valid option CTM!" << endl;
            break;
        }

    } while (option >= 1 || option <= 7);
}

int main(){
    Menu();
    return 0;
}

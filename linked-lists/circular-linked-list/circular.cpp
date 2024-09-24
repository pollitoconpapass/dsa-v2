#include "Node.h"
using namespace std;

class CircularLinkedList{
public: 
    Node *head;

    // === CONSTRUCTOR ===
    CircularLinkedList(){
        head = NULL;
    }
    CircularLinkedList(Node *node){
        head = node;
    }

    // === METHODS ===

    // 1. Check if a Node exists based on its key
    Node *checkNodeExists(int key){
        Node *temp = NULL;
        Node *ptr = head;

        if(ptr == NULL){  // -> when it is empty
            return temp;
        }
        else{
            do {  // -> this will execute first, and then verify the while condition
                if(ptr->key == key){ // -> when the key of the pointer is equal to the key we pass as argument... 
                    temp = ptr; // -> ... store that address into temp
                }
                ptr = ptr->next;  // -> to keep iterating over the linked list
            } while (ptr != head);  // -> when ptr is equal to head, it means we reached the final Node, as the final Node is pointing to the head address. 
            // (REMEMBER: Theory of the Circular Linked List)

            return temp;
        }
    }

    // 2. Append a new node to the list (at the end of the list)
    void appendNode(Node *newNode){
        if (checkNodeExists(newNode->key) != NULL){
            cout << "Node with key " << newNode->key << " already exists..." << endl;
        }
        else{
            if (head == NULL){  // -> if it's the first element to append.
                head = newNode; // -> the head will be assigned to the address of the new node 
                newNode->next = head;  // -> as it's a circular linked list, the last element should be pointing to the head...
                cout << "Node appended correctly as first value!" << endl;
            }
            else {
                Node *ptr = head; // -> create a ptr to the head node

                while(ptr->next != head){ // -> while it's not the last one, (REMEMBER: the last node will always have its newxt pointer pointing to the head. ALWAYS!)
                    ptr = ptr->next; // -> keep moving
                }

                ptr->next = newNode; // -> once you reached the last node, change the next pointer to point the address of the new node
                newNode->next = head; // -> and the next pointer of the node will point to the head

                cout << "Node appended succesfully" << endl;
            }
        }
    }

    // 3. Prepend a Node (at the beginning of the list)
    void prependNode(Node *n){
        if (checkNodeExists(n->key)!= NULL){
            cout << "Node with key " << n->key << " already exists!" << endl;
        }
        else {
            if (head == NULL){ // if it's the first value in the list
                head = n;
                n->next = head;
                cout << "Node prepended as first value successfully" << endl;
            }
            else {
                Node *ptr = head; // -> create a ptr that stores the head address
            
                while(ptr->next != head){
                    ptr = ptr->next; // -> iterate over the list until reaching the final node
                }
                ptr->next = n; // -> assign the next pointer of the last node to the new node address
                // Because the last node should always point to the head, and as the new node is going to be the head... we establish that connection 

                n->next = head;  // ->  the next pointer of the new node will point to the (at that moment) head of the list
                head = n; // -> and the head will now be the new node we're passing
                cout << "Node prepended successfully!" << endl;
            }
        }
    }

    // 4. Insert a Node after a given (already existing node's) key
    void insertNodeAfter(int key, Node *newNode){
        Node *ptr = checkNodeExists(key);

        if (ptr == NULL){
            cout << "ERROR: There's no existing node with the key: " << key << endl;
        }
        else {
            if(checkNodeExists(newNode->key) != NULL){
                cout << "The key of the new node to insert already exists..." << endl;
                cout << "Append another node with a different key value" << endl;
            }
            else {
                // insert at the end
                if (ptr->next == head){ 
                    newNode->next = head; // -> the next pointer is gonna point to head (as the last element should ALWAYS point to the head in a circular linked list)
                    ptr->next = newNode;  // -> now the next pointer of the existing node, is gonna point to the new one's address
                    cout << "Node inserted at the end successfully!" << endl;
                }

                // insert in between
                else {
                    newNode->next = ptr->next; // -> the next pointer of the new node will now store the address that the existing node (the node we are gonna insert the new node after) had until that moment.
                    ptr->next = newNode; // -> and the next pointer of the existing node will now store the new node address. creating the insertion between them. 
                    cout << "Node inserted in between successfully!" << endl;
                }
            }
        }
    }

    // 5. Delete a Node given a key
    void deleteNode(int key){
        Node *ptr = checkNodeExists(key);

        if (ptr == NULL){
            cout << "There is no node with key " << key << endl;
        }
        else {
            if (head == NULL){
                cout << "The linked list is already empty" << endl;
            }

            // If the node to delete is the head
            else if (ptr == head){ 
                if (head->next == head){  // -> if it's the head and the only element in the list
                    head = NULL; // -> just assign NULL to it
                    cout << "Head node unlinked successfully" << endl;
                }
                else {
                    Node *ptr = head; // -> create a ptr that starts in head
                    while(ptr->next != head){ 
                        ptr = ptr->next;  // -> we iterate over the whole list until reaching the last element
                    }

                    ptr->next = head->next; // -> the next pointer of the last element wil now have the same address as the next pointer of the (at that moment) head node
                    head = head->next; // -> now change the head the address of the next node of (the at that moment) head
                    cout << "Node unlinked successfully!" << endl;
                }
            }

            // If the node to delete is NOT the head
            else {
                Node *temp = NULL;
                Node *prevptr = head; // -> initialize a prevptr pointing to the address in head
                Node *currentptr = head->next;  // -> the currentptr point to the address of the next pointer of head

                while(currentptr != NULL){
                    if(currentptr->key == key){ // -> when the currentptr key is the same as the one you pass as argument
                        temp = currentptr; // -> assign currentptr to temp
                        currentptr = NULL; // -> we make currentptr NULL to exit the while loop
                    }
                    else { // -> if we still don't find the matching key
                        prevptr = prevptr->next; // -> continue iterating
                        currentptr = currentptr->next; // -> continue iterating...
                    }
                }

                prevptr->next = temp->next; // -> now the next pointer of prevptr (the previous node of the one to delete)... 
                // ... is gonna store the address of the next pointer of temp (temp had the address of the node to delete) so it will create a new connection skipping the node to delete
                cout << "Node unlinked successfully!" << endl;
            }
        }
    }

    // 6. Update a Node given a key
    void updateNodeByKey(int key, int newValue){
        Node *ptr = checkNodeExists(key);

        if(ptr != NULL){
            ptr->key = newValue;
            cout << "Node with key " << key << "updated succesfully" << endl;
        }
        else {
            cout << "Node with key " << key << "does not exist" << endl;
        }
    }

    // 7. Show the Circular Linked List
    void showCircularLinkedList(){
        if(head == NULL){
            cout << "No Nodes present in the Linked List" << endl;
        }
        else {
            cout << "Circular Linked List: " << endl;

            Node *temp = head;

            do {
                cout << "(" << temp->key << " | " << temp->data << " | " << temp->next <<  ") --> " ;
                temp = temp->next;
            } while (temp != head); // -> as a circular linked list, the last element will point to the head, 
                                // ... so it will iterate until temp has reached the head address again. That will be the last node
        }
    }
};

void Menu(){
    CircularLinkedList circularLinkedList;

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
        cout << "6. Print the circular linked list" << endl;
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

            circularLinkedList.appendNode(node);
            break;

        case 2: 
            cout << "Enter the respective values to prepend a new Node... " << endl;
            cout << "Key: "; cin >> key;
            cout << "Data: "; cin >> data;

            node->data = data;
            node->key = key;

            circularLinkedList.prependNode(node);
            break;

        case 3: 
            cout << "Enter the respective values to insert a new node after a key... " << endl;
            cout << "Key to insert after: "; cin >> key2Insert;
            cout << "Key of the new node: "; cin >> key;
            cout << "Data of the new node: "; cin >> data;

            node->data = data;
            node->key = key;

            circularLinkedList.insertNodeAfter(key2Insert, node);
            break;

        case 4: 
            cout << "Enter the respective values to delete a Node..." << endl;
            cout << "Key of the node to delete: "; cin >> key;

            circularLinkedList.deleteNode(key);
            break;

        case 5:
            cout << "Enter the respective values to update a Node..." << endl;
            cout << "Key of the Node to update: "; cin >> key;
            cout << "New data of the Node: "; cin >> data;

            circularLinkedList.updateNodeByKey(key, data);
            break;

        case 6: 
            cout << endl;
            circularLinkedList.showCircularLinkedList();
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

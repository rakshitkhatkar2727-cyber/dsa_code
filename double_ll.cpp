#include <iostream>
using namespace std;

// 1. Define the basic building block (a Node)
struct Node {
    int data;
    Node* prev; // Arrow pointing backward
    Node* next; // Arrow pointing forward
};

// 2. Function to add a number to the end of the list
void insert(Node*& head, int value) {
    // Create a new box (Node) in memory
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // If the list is empty, this new node becomes the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Otherwise, travel to the very end of the list
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Connect the last node to our new node...
    temp->next = newNode;
    
    // ...AND connect the new node back to the last node! 
    // (This is the ONLY difference from a singly linked list)
    newNode->prev = temp; 
}

// 3. Function to print out the list
void printList(Node* head) {
    Node* temp = head; 
    
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 4. Test it out!
int main() {
    Node* head = nullptr; // Start with a completely empty list

    // Add some numbers
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    // Print them out
    printList(head); 
    // Output: List: 10 <-> 20 <-> 30 <-> NULL

    return 0;
}
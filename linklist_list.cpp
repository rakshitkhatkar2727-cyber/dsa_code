#include <iostream>
using namespace std;

// 1. Define the basic building block (a Node)
struct Node {
    int data;
    Node* next; // Pointer to the next node
};

// 2. Function to add a number to the end of the list
// Notice the '&' - we pass the head by reference so we can change it!
void insert(Node*& head, int value) {
    // Create a new box (Node) in memory
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr; // It will be the last item, so it points to nothing

    // If the list is completely empty, this new node becomes the head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Otherwise, travel to the very end of the list
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Connect the last node to our new node
    temp->next = newNode;
}

// 3. Function to print out the list
void printList(Node* head) {
    Node* temp = head; // Start at the beginning
    
    // Keep hopping to the next node until we hit the end (nullptr)
    while (temp != nullptr) {
        cout << temp->data << " -> ";
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
    cout << "My Linked List: ";
    printList(head); 
    // Output: 10 -> 20 -> 30 -> NULL

    return 0;
}
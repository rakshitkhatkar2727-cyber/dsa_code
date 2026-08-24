#include <iostream>
using namespace std;

// 1. Define our basic Node
struct Node {
    int data;
    Node* next;
};

// 2. Helper function to find the maximum number in the list
// We need this to know how many digits our biggest number has
int getMax(Node* head) {
    int maxVal = head->data;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data > maxVal) {
            maxVal = temp->data;
        }
        temp = temp->next;
    }
    return maxVal;
}

// 3. The Main Radix Sort Logic
void radixSort(Node*& head) {
    // If the list is empty or has only one item, it's already sorted
    if (head == nullptr || head->next == nullptr) return;

    int maxVal = getMax(head);

    // Loop through the places (1s place, 10s place, 100s place...)
    for (int place = 1; maxVal / place > 0; place *= 10) {
        
        // Create 10 buckets (for digits 0 through 9)
        // We keep track of the start (head) and end (tail) of each bucket
        Node* bucketHeads[10] = {nullptr};
        Node* bucketTails[10] = {nullptr};

        // Step A: Distribute nodes into the 10 buckets based on their current digit
        Node* current = head;
        while (current != nullptr) {
            // Find out which digit we are looking at
            int digit = (current->data / place) % 10;
            
            // Save the next node before we break the current link
            Node* nextNode = current->next;
            current->next = nullptr; // Detach the node

            // Put the node into the correct bucket
            if (bucketHeads[digit] == nullptr) {
                // If the bucket is empty, this node is both head and tail
                bucketHeads[digit] = current;
                bucketTails[digit] = current;
            } else {
                // Attach to the end of the bucket and update the tail
                bucketTails[digit]->next = current;
                bucketTails[digit] = current;
            }
            
            // Move to the next node in our original list
            current = nextNode;
        }

        // Step B: Reconnect all the buckets back into one single list
        head = nullptr;
        Node* tail = nullptr;

        for (int i = 0; i < 10; i++) {
            if (bucketHeads[i] != nullptr) { // If the bucket isn't empty
                if (head == nullptr) {
                    // First non-empty bucket becomes the start of our new list
                    head = bucketHeads[i];
                    tail = bucketTails[i];
                } else {
                    // Connect the end of our new list to the start of this bucket
                    tail->next = bucketHeads[i];
                    tail = bucketTails[i]; // Update the very end of our list
                }
            }
        }
    }
}

// 4. Helper to insert a new node at the end
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 5. Helper to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// 6. Test the code!
int main() {
    Node* head = nullptr;

    insert(head, 170);
    insert(head, 45);
    insert(head, 75);
    insert(head, 90);
    insert(head, 802);
    insert(head, 24);
    insert(head, 2);
    insert(head, 66);

    cout << "Unsorted List:\n";
    printList(head);

    radixSort(head);

    cout << "\nSorted List:\n";
    printList(head);
    // Output: 2 -> 24 -> 45 -> 66 -> 75 -> 90 -> 170 -> 802 -> NULL

    return 0;
}
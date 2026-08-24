#include <iostream>
using namespace std;

#define SIZE 5 // Set the maximum size of our queue to 5

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    // Initialize the queue to be completely empty
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // 1. Add an item to the queue (Enqueue)
    void enqueue(int value) {
        // Check if the queue is completely full
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is Full! Cannot add " << value << endl;
            return;
        }
        
        // If it's the very first item being added, set front to 0
        if (front == -1) {
            front = 0;
        }
        
        // Move the rear pointer circularly and add the new value
        rear = (rear + 1) % SIZE; 
        items[rear] = value;
        cout << "Inserted: " << value << endl;
    }

    // 2. Remove an item from the queue (Dequeue)
    void dequeue() {
        // Check if the queue is already empty
        if (front == -1) {
            cout << "Queue is Empty! Nothing to remove." << endl;
            return;
        }
        
        cout << "Removed: " << items[front] << endl;
        
        // If this was the last item in the queue, reset it back to empty
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Otherwise, move the front pointer circularly
            front = (front + 1) % SIZE;
        }
    }

    // 3. Print out the queue
    void display() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;     // Stop when we reach the last element
            i = (i + 1) % SIZE;       // Move index circularly
        }
        cout << endl;
    }
};

// 4. Test it out!
int main() {
    CircularQueue q;

    // Fill up the queue (Max size is 5)
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    // Try to add one more (Should print "Queue is Full")
    q.enqueue(60); 

    q.display(); // Output: 10 20 30 40 50

    cout << "\n-- Removing two items --\n";
    q.dequeue(); // Removes 10
    q.dequeue(); // Removes 20

    cout << "\n-- Adding two new items (Notice how they wrap around to the front!) --\n";
    q.enqueue(60); 
    q.enqueue(70);

    q.display(); // Output: 30 40 50 60 70

    return 0;
}
# Basic C++ Doubly Linked List

This repository contains a simple, beginner-friendly implementation of a **Doubly Linked List** in C++. I created this to understand how nodes can point both forward and backward in memory.

## 📝 What's Inside
- **No complex classes:** Just a simple C-style `struct` for the Node.
- **Two-Way Pointers:** Each node has a `next` pointer (moving forward) and a `prev` pointer (moving backward).
- **Insert Function:** Adds a new number to the end of the list and automatically connects both pointers.
- **Print Function:** Walks through the list to print the output in a clean format (`10 <-> 20 <-> 30`).

## 🚀 How to Run It

1. Download or clone this repository.
2. Open your terminal and compile the code using `g++`:
   ```bash
   g++ DoublyLinkedList.cpp -o run_list
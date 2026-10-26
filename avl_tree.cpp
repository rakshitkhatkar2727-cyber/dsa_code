
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        height = 1;
        left = right = nullptr;
    }
};

// Get height of a node
int getHeight(Node* node) {
    if (node == nullptr)
        return 0;

    return node->height;
}

// Update height of a node
void updateHeight(Node* node) {
    if (node != nullptr) {
        node->height = 1 + max(
            getHeight(node->left),
            getHeight(node->right)
        );
    }
}

// Calculate balance factor
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;

    return getHeight(node->left) -
           getHeight(node->right);
}

// Right rotation (LL case)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation (RR case)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Balance a node using rotations
Node* balanceNode(Node* node) {
    if (node == nullptr)
        return nullptr;

    updateHeight(node);

    int balance = getBalance(node);

    // LL case
    if (balance > 1 &&
        getBalance(node->left) >= 0) {
        return rightRotate(node);
    }

    // LR case
    if (balance > 1 &&
        getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RR case
    if (balance < -1 &&
        getBalance(node->right) <= 0) {
        return leftRotate(node);
    }

    // RL case
    if (balance < -1 &&
        getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Insert a key
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else {
        cout << "Duplicate keys are not allowed.\n";
        return root;
    }

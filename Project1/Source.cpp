#include <iostream>
using namespace std;

// Define a structure Node
struct Node {
    int key;
    int data;
    Node* next; // pointer to next node

    // Default constructor
    Node() {
        key = 0;
        data = 0;
        next = NULL;
    }

    // Parameterized constructor
    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
    }
};

int main() {
    // Create two nodes using parameterized constructor
    Node n1(1, 10);
    Node n2(2, 20);

    // Connect the nodes (like a linked list)
    n1.next = &n2;

    // Display the data
    cout << "Node 1 -> Key: " << n1.key << ", Data: " << n1.data << endl;
    cout << "Node 2 -> Key: " << n1.next->key << ", Data: " << n1.next->data << endl;

    return 0;
}

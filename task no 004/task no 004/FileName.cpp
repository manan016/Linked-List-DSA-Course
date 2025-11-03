#include<iostream>
using namespace std;

class Node {
public:
    int roll;
    string name;
    string dep;
    Node* next;

    Node(int r, string n, string d) {
        roll = r;
        name = n;
        dep = d;
        next = nullptr;
    }
};

class list {
    Node* head;
    Node* tail;

public:
    list() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int r, string n, string d) {
        Node* newNode = new Node(r, n, d);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int r, string n, string d) {
        Node* newNode = new Node(r, n, d);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    //  Remove first node
    void pop_front() {
        if (head == nullptr) {
            cout << "List is empty! Nothing to remove.\n";
            return;
        }

        Node* temp = head;  // store current first node
        head = head->next;  // move head to next node
        cout << "Removed (front): " << temp->name << endl;
        delete temp;         // free memory

        if (head == nullptr) // if list became empty
            tail = nullptr;
    }

    //  Remove last node
    void pop_back() {
        if (head == nullptr) {
            cout << "List is empty! Nothing to remove.\n";
            return;
        }

        // if there's only one node
        if (head == tail) {
            cout << "Removed (back): " << head->name << endl;
            delete head;
            head = tail = nullptr;
            return;
        }

        // move to 2nd last node
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        cout << "Removed (back): " << tail->name << endl;
        delete tail;        // delete last node
        tail = temp;        // make 2nd last node new tail
        tail->next = nullptr;
    }

    void print() {
        cout << "\n=== Student List ===\n";
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->name
                << ", Roll: " << temp->roll
                << ", Dept: " << temp->dep << " --> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    list ll;
    ll.push_front(101, "Ali", "CS");
    ll.push_front(102, "Sara", "IT");
    ll.push_back(103, "Hamza", "SE");
    ll.push_back(104, "Ayesha", "AI");

    ll.print();

    ll.pop_front();  // removes "Sara"
    ll.print();

    ll.pop_back();   // removes "Ayesha"
    ll.print();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct StudentNode {
    string name;
    StudentNode* next;
    StudentNode(string n) {
        name = n;
        next = nullptr;
    }
};

StudentNode* head = nullptr;

void addStudent(string name) {
    StudentNode* newNode = new StudentNode(name);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        StudentNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << name << " added to roll call.\n";
}

void removeStudent(string name) {
    if (head == nullptr) {
        cout << "Roll call is empty!\n";
        return;
    }
    if (head->name == name) {
        StudentNode* temp = head;
        head = head->next;
        delete temp;
        cout << name << " removed.\n";
        return;
    }
    StudentNode* previous = head;
    StudentNode* current = head->next;
    while (current != nullptr && current->name != name) {
        previous = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << name << " not found in roll call.\n";
    }
    else {
        previous->next = current->next;
        delete current;
        cout << name << " removed.\n";
    }
}

void displayRollCall() {
    if (head == nullptr) {
        cout << "No students in class.\n";
        return;
    }
    cout << "Roll Call:\n";
    StudentNode* current = head;
    while (current != nullptr) {
        cout << "- " << current->name << "\n";
        current = current->next;
    }
}

int main() {
    int choice;
    string name;

    while (true) {
        cout << "\n--- Student Roll Call Manager ---\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Display Roll Call\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            addStudent(name);
        }
        else if (choice == 2) {
            cout << "Enter name to remove: ";
            cin.ignore();
            getline(cin, name);
            removeStudent(name);
        }
        else if (choice == 3) {
            displayRollCall();
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    while (head != nullptr) {
        StudentNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
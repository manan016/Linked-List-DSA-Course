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
	void print() {
		cout << "\n=== Student List ===\n";
		Node* temp = head;
		while (temp != nullptr) {
			cout << "Name: " << temp->name
				<< ", Roll: " << temp->roll
				<< ", Dept: " << temp->dep << " --> ";
			cout << "NULL\n";
			temp = temp->next;
		}

	}

};
int main() {
	list ll;
	ll.push_front(101, "ali ", "CS");
	ll.push_front(102, "Sara", "IT");
	ll.push_back(103, "Hamza", "SE");
	ll.push_back(104, "Ayesha", "AI");
	ll.print();
}
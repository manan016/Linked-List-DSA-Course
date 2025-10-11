#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
int main() {
	Node* head = new Node();
	head->data = 10;
	head->next = nullptr;
	cout << " This is first value :"<<head->data << endl;

	Node* second = new Node();
	second->data = 20;
	second->next = nullptr;
	cout << " This is first value :" << second->data << endl;

	Node* third = new Node();
	third->data = 30;
	third->next = nullptr;
	cout << " This is first value :" << third->data << endl;

	head->next = second;
	second->next = third;


	
	Node* previous = head;
	while (previous->next->next != nullptr) {
		previous = previous->next;
	}

	Node* nodeToDelete = previous->next;  
	previous->next = nullptr;            
	delete nodeToDelete;

	 nodeToDelete = head->next;      
	head->next = nodeToDelete->next;     
	delete nodeToDelete;
	  
	nodeToDelete = head;  
	head = head->next;          
	delete nodeToDelete;

	Node* current = head;
	while (current != nullptr) {
		cout << current->data << "-> ";
		current = current->next;
	}
	cout << endl;
}
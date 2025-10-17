#include<iostream>
#include<vector>
using namespace std;
struct Node {
	int data;
	Node* next;
	
};
int main() {
	Node* head = new Node();
	head->data = 1;

	Node* node2 = new Node();
	node2->data = 2;
	Node* node3 = new Node();
	node3->data = 3;
	Node* node4 = new Node();
	node4->data = 4;
	Node* node5 = new Node();
	node5->data = 5;
	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	vector<int>values;

	Node* current = head;
	while (current != nullptr) {
		values.push_back(current->data);
		current = current->next;


	}
	cout << "Reversed order: ";
	for (int i = values.size() - 1; i >= 0; i--) {
		cout << values[i] << " ";
	}
	return 0;


}
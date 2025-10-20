#include<iostream>
using namespace std;
class stack {
	int arr[6];
	int top;

public:
	stack() {
		top = -1;
	}
	void push(int x) {
		if (top == 5) {
			cout << "Stack is overflow " << endl;
			return;
		}
		arr[++top] = x;
	}
	void pop() {
		if (top == -1) {
			cout << "Stack is underflow " << endl;
			return;
		}
		cout << "Popped element is: " << arr[top] << endl;
		top--;
	}
	void display() {
		if (top == -1) {
			cout << "Stack is empty " << endl;
			return;
		}
		cout << "Stack elements are: ";
		for (int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	stack s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	s.pop();
}
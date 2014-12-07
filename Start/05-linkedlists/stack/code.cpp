#include <iostream>
using namespace std;

class Node {
	public:
		Node *next;
		int value;

		Node() {
			next = NULL;
			value = 0;
		}

		Node(int value) {
			next = NULL;
			this->value = value;
		}
};

class Stack {
	private:
		Node head;

	public:
		Stack() {}
		~Stack() {
			while(head.next != NULL) {
				Node *topNode = head.next;
				head.next = topNode->next;
				delete topNode;
			}
		}

		bool isEmpty() const {
			if (head.next == NULL) return true;
			else return false;
		}

		void push(int newValue) {
			Node *newNode = new Node(newValue);
			newNode->next = head.next;
			head.next = newNode;
		}

		int pop() {
			if(isEmpty()) throw "pop on empty list";

			Node *topNode = head.next;
			int topValue = topNode->value;
			head.next = topNode->next;
			delete topNode;
			return topValue;
		}

};

int main() {
	Stack stack;
	int z;
	cin >> z;
	while(z--) {
		string operation;
		cin >> operation;
		if(operation == "POP") {
			if(stack.isEmpty()) {
				cout << "EMPTY\n";
			} else{
				cout << stack.pop() << "\n";
			}
		} else {
			int value;
			cin >> value;
			stack.push(value);
		}
	}
	return 0;
}

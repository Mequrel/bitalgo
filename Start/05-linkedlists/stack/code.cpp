#include <iostream>
using namespace std;

struct Node {
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
			clear();
		}

		bool isEmpty() const {
			return (head.next == NULL);
		}

		void push(int newValue) {
			Node *newNode = new Node(newValue);
			newNode->next = head.next;
			head.next = newNode;
		}

		void pop() {
			if(isEmpty()) throw "pop on empty list";

			Node *topNode = head.next;
			head.next = topNode->next;
			delete topNode;
		}
		
		int top() {
			if(isEmpty()) throw "top on empty list";
			Node *topNode = head.next;
			return topNode->value;
		}

		void clear() {
				while(head.next != NULL) {
				Node *topNode = head.next;
				head.next = topNode->next;
				delete topNode;
			}
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

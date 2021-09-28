#include <bits/stdc++.h>
using namespace std;

// find the middle element of the linked list

class Node {
public:
	int data;
	Node* next;

	Node () {
		this -> next = NULL;
	}

	Node (int data) {
		this -> data = data;
		this -> next = NULL;
	}
};

// in case of even gives second element
Node* middleElement(Node* head){
	Node *slow = *fast = head;

	while (fast != NULL && fast -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next;
	}

	return slow;
}

int main() {
	return 0;
}
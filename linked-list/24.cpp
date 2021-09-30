#include <bits/stdc++.h>
using namespace std;

// reverse doubly linked list in groups of given size

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node () {
		this -> next = NULL;
		this -> prev = NULL;
	}

	Node (int data) {
		this -> data = data;
		this -> next = NULL;
		this -> prev = NULL;
	}
};

Node* reverseInGroups (Node* head) {

	// reverse first 7 nodes
	int count = 0;
	Node *curr = head;
	while (count < n && curr != NULL) {
		Node* temp = curr -> prev;
		curr -> prev = curr -> next;
		curr -> next = temp;
		curr = curr -> prev;
	}

	
}

int main() {
	return 0;
}
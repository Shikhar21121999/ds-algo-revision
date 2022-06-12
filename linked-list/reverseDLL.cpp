#include <bits/stdc++.h>
using namespace std;

// Reverse a doubly linked list

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

void reverse (Node **head_ref) {

	if (*head_ref == NULL or *head_ref -> next == NULL) {
		return;
	}

	Node *curr = *head_ref;

	while (curr != NULL) {
		Node *temp = curr -> prev;
		curr -> prev = curr -> next;
		curr -> next = temp;
		curr = curr -> prev;
	}
	
	*head_ref = temp -> prev;
}

int main() {
	return 0;
}
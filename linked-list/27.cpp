#include <bits/stdc++.h>
using namespace std;

// clone a linked list with next and random pointer

class Node {
public:
	int data;
	Node* next;
	Node* arb;

	Node () {
		this -> next = NULL;
		this -> arb = NULL;
	}

	Node (int data) {
		this -> data = data;
		this -> next = NULL;
	}
};

Node* cloneList (Node* head) {

	Node* newhead = NULL;

	Node* curr = head;
	
	// copy by inserting in between
	while(curr != NULL) {
		Node *new_node = new Node(curr -> data);
		new_node -> next = curr -> next;
		curr -> next = new_node;
		curr = new_node -> next;
	}

	// add random pointers
	curr = head;
	while (curr != NULL) {
		curr -> next -> arb = curr -> arb -> next;
		curr = curr -> next -> next;
	}

	// seprate the two linked lists
	Node *newHead = head -> next;
	curr = head;
	Node* newCurr = newHead;

	while(curr != NULL) {
		curr -> next = newCurr -> next;
		newCurr -> next = newCurr -> next -> next;
		curr = curr -> next;
		newCurr = newCurr -> next;
	}

	curr -> next = NULL;

	return newHead;


}

int main() {
	return 0;
}
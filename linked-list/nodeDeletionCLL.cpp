#include <bits/stdc++.h>
using namespace std;

// Deletion from a circular linked list

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

Node* getTailCll (Node* head) {
	Node* curr = head;

	while(curr -> next != head){
		curr = curr -> next;
	}
	return curr;
}

Node* deleteNodeCll(Node* head, int data) {

	// get a pointer to the node to be deleted
	Node *curr = head;
	Node *prev = NULL;

	while(curr -> next != head){
		if (curr -> data == data) {
			break;
		}
		prev = curr;
		curr = curr -> next;
	}

	// if curr is the first node
	if (curr == head) {
		Node *tail = getTail(head);
		tail -> next = head -> next;
		head = head -> next;
	} else if (curr -> next == head){ // if last node
		prev -> next = head;
	} else {
		prev -> next = curr -> next;
	}
	return head;
} 




int main() {
	return 0;
}
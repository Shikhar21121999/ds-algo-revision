#include <bits/stdc++.h>
using namespace std;

// rotate doubly linked list by n nodes

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

Node* getTail (Node *head) {

	if (head == NULL or head -> next == NULL) {
		return head;
	}

	Node *curr = head;

	while (curr -> next != NULL){
		curr = curr -> next;
	}
	return curr;

}

Node* rotateDoublyLnikedList (Node *head, int n) {

	Node *tail = getTail(head);

	// make it a circular doubly linked list
	tail -> next = head;
	head -> prev = tail;

	int count = 0;
	// move head n time forward
	while(head -> next != NULL and count < n) {
		head = head -> next;
	}
	head -> prev -> next = NULL;
	head -> prev = NULL;
}

int main() {
	return 0;
}
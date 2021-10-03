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

Node* reverseInGroups (Node* head, int k) {

	// reverse first k nodes
	int count = 0;
	Node *curr = head;
	Node *newHead = NULL;
	while (count < n && curr != NULL) {
		newHead = curr;
		Node* temp = curr -> prev;
		curr -> prev = curr -> next;
		curr -> next = temp;
		curr = curr -> prev;
		count ++;
	}

	// if count >= k it means there are nodes remaining
	if (count >= k) {
		Node* rest = reverseInGroups(curr, k);
		head -> next = rest;
		if (rest != NULL) {
			rest -> prev = head;
		}
	}

	return newHead;
	
}

int main() {
	return 0;
}
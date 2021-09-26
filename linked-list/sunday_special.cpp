#include <bist/stdc++.h>
using namespace std;

class Node {
	Node* next;
	int data;

	Node () {
		this -> next = NULL;
		this -> data = -1;
	}

	Node (int data) {
		this -> next = NULL;
		this -> data = data;
	}
};

// reverse iteratively
void reverseIterative(Node* head) {
	Node *prev = *curr = nxt = NULL;
	curr = head;

	while (curr != NULL) {
		nxt = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = nxt;
	}
	return prev;
}

// reverse recursively
Node* reverseRecur (Node* head) {
	if(head == NULL or head -> next == NULL) {
		return head;
	}

	Node *rest = reverseRecur(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return rest;
}

// reverse in groups of given size
Node* reverseInGroups (Node* head, int k) {

	Node *prev = *curr = *nxt = NULL;
	int count = 0;

	if (head == NULL) {
		return head;
	}

	while(curr != NULL && count < k){
		nxt = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = curr -> next;
		cout += 1;
	}

	head -> next = reverseInGroups(next, k);

	return prev;
}

// loop detection origin
Node* detectLoopOrigin(Node *head) {

	Node *slow = *fast = NULL;
	
	while (slow	!= NULL && fast != NULL && fast -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
		if (slow == fast) {
			break;
		}
	}

	if (slow != fast) {
		return NULL;
	}

	slow = head;

	while (slow != fast){
		slow = slow -> next;
		fast = fast -> next;
	}

	return slow;
}

// remove duplicates from a sorted linked list
Node* removeDuplicates(Node *head) {

	// base case
	if (head == NULL or head -> next == NULL) {
		return head;
	}

	Node *prev = head;
	Node *curr = head -> next;

	while(curr != NULL) {
		if (curr -> data != prev -> data) {
			prev -> next = curr;
			prev = curr;
		}
		curr = curr -> next;
	}
	prev -> next = curr;

	return head;
}

// remove duplicates from an unsorted linked list
Node* removeDuplicatesUnsorted (Node *head) {
	
	// base case
	if (head == NULL or head -> next == NULL) {
		return head;
	}

	unordered_set <int> dict;
	Node *prev = head;
	Node *curr = prev -> next;

	while(curr != NULL) {
		if (dict.find(curr -> data) == dict.end()) {
			prev -> next = curr;
			prev = curr;
			dict.insert(curr -> data);
		}
		curr = curr -> next;
	}
	prev -> next = curr;

	return head;
}

// move last element to the first of the linked list
Node* moveToFirst (Node* head) {

	// base case
	if (head == NULL or head -> next == NULL) {
		return head;
	}

	Node *sec_last = head;
	Node *last = head -> next;

	while (last -> next != NULL) {
		last = last -> next;
		sec_last = sec_last -> next;
	}

	sec_last -> next = NULL;
	last -> next = head;
	head = last;

	return head;
}

Node* getTail (Node* head){
	Node *prev = head;

	while(head != NULL) {
		prev = head;
		head = head -> next;
	}
	return prev;
}

void push (Node* head, int d) {
	if (head -> next == NULL and head -> data == -1) {
		Node *new_node = new Node(d);
		return new_node;
	}
	else {
		Node* tail = getTail(head);
		Node* new_node = new Node(d);
		tail -> next = new_node;
	}
}

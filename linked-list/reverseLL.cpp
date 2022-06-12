#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node() {
		this->data = 0;
		this->next = NULL;
	}

	Node (int a) {
		this->data = a;
		this->next = NULL;
	}
};

class LinkedList {
public:
	Node* head;
	LinkedList() {
		this->head = NULL;
	}

	void reverseIterative () {
		Node* curr = this->head;
		Node* prev = NULL;
		Node* next = NULL;
		while(curr != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		this->head = prev;
	}

	void insertOne (int d) {

		Node* newNode = new Node(d);
		if (this->head == NULL) {
			this->head = newNode;
			return;
		}

		Node* curr = this->head;
		while(curr->next != NULL) {
			curr = curr->next;
		}


		curr->next = newNode;
	}

	void printList () {
		
		Node* curr = this->head;

		if(this->head == NULL) {
			cout<<"List Empty"<<endl;
			return;
		}
		while(curr != NULL){
			cout << curr->data << " ";
			curr = curr->next;
		}
	}

	void reverseRecur () {
		if (this->head == NULL || this->head->next == NULL) {
			return;
		} else {
			// break it into two linked list
			LinkedList rest;
			rest->head = this->head->next;
			rest.reverseRecur();
			// Node* rest = reverseRecur(head->next);
			this->head->next->next = head;
			this->head->next = NULL;
			return;
		}
	}
};

int main() {
	// create a linked list
	LinkedList l1;
	l1.insertOne(4);
	l1.insertOne(5);
	l1.insertOne(7);
	l1.printList();
	cout<<endl;
	l1.reverseRecur();
	l1.printList();
}
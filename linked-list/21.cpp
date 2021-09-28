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

void pairTripSum (Node *head, int x) {

	Node* curr = head;
	Node* left = curr -> next;
	Node* tail = getTail(head);
	bool found = false;

	while(curr -> next -> next != NULL) {
		left = curr -> next;
		right = tail;
		while (left != right) {
			int sum = left -> data + right -> data + curr -> data;
			if (sum == x) {
				found = true;
				cout << left -> data << " " << right -> data << endl;
				left = left -> next;
				right = right -> prev;
			} else if (sum < x) {
				left = left -> next;
			} else {
				right = right -> prev;
			}
		}

		if (!found) {
			cout << "No pair found" << endl;
		}
	}
	
}

int main() {
	return 0;
}
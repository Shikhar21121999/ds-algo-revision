#include <bits/stdc++.h>
using namespace std;

// Partitioning a linked list around a given value and keeping the original order

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

Node* partitionPiv (Node* head, int piv) {
	Node* lessHead = NULL;
	Node* greatHead = NULL;
	Node* eqHead = NULL;
	Node* lessCurr = NULL;
	Node* greatCurr = NULL;
	Node* eqCurr = NULL;
	Node* curr = NULL;

	while(curr != NULL) {
		if (curr -> data < piv) {
			if (lessHead == NULL) {
				lessHead = curr;
				lessCurr = curr;
			} else {
				lessCurr -> next = curr;
				lessCurr = lessCurr -> next;
			}
		} else if (curr -> data == piv) {
			if (eqHead == NULL) {
				eqHead = curr;
				eqCurr = curr;
			} else {
				eqCurr -> next = curr;
				eqCurr = eqCurr -> next;
			}
		} else if (curr -> data > piv) {
			if (greatHead == NULL) {
				greatHead = curr;
				greatCurr = curr;
			} else {
				greatCurr -> next = curr;
				greatCurr = greatCurr -> next;
			}
		}
		curr = curr -> next;
	}

	// joining the linked lists

	// smaller list is empty
	if (lessHead == NULL) {
		if (eqHead == NULL) {
			return greatHead;
		}
		eqCurr -> next = greatHead;
		return eqHead;
	}

	// if equal list is empty
	if (eqHead == NULL) {
		lessHead -> next = greatHead;
		return lessHead;
	}

	// if smaller and equal list are non-empty
	lessCurr -> next = eqHead;
	eqCurr -> next = greatHead;
	return lessHead;

}

int main() {
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

// sort a linked list of 0's, 1's and 2's

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

// call with piv = 0
Node* partitionPiv(Node* head, int piv) {

	Node *lessHead = *lessCurr = NULL;
	Node *eqHead = *eqCurr = NULL;
	Node *greatHead = *greatCurr = NULL;
	Node *curr = head;

	while(curr != NULL) {

		if (curr -> data < piv) {
			if (lessHead == NULL){
				lessHead = curr;
				lessCurr = curr;
			} else {
				lessCurr -> next = curr;
				lessCurr = curr;
			}
		} else if (curr -> data == piv) {
			if (eqHead == NULL) {
				eqHead = curr;
				eqCurr = curr;
			} else {
				eqCurr -> next = curr;
				eqCurr = curr;
			}
		} else {
			if (greatHead == NULL) {
				greatHead -> next = curr;
				greatCurr = curr;
			} else {
				greatCurr -> next = curr;
				greatCurr = curr;
			}
		}
	}

	// if  smaller list is empty
	if (lessHead == NULL) {
		if (eqHead == NULL) {
			return greatHead;
		}
		eqCurr -> next = greatHead;
		return eqHead;
	}

	// if equal list is empty
	if (eqHead == NULL) {
		lessCurr -> next = greatHead;
		return lessHead;
	}

	// if smaller list is non empty and equal list is non empty
	lessCurr -> next = eqHead;
	eqCurr -> next = greatHead;
	return lessHead;

}

int main() {
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

// segregate even and odd nodes in a linked list

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

// segregate even and odd nodes in a linked list
Node* segregateEvenOdd(Node* head) {
	Node *evenHead = *evenCurr = NULL;
	Node *oddHead = *oddCurr = NULL;

	Node *curr = head;
	while(curr != NULL) {
		if (curr -> data % 2 == 0) {
			if (evenHead == NULL) {
				evenHead = curr;
				evenCurr = curr;
			} else {
				evenCurr -> next = curr;
				evenCurr = curr;
			}
		} else {
			if (oddHead == NULL) {
				oddHead = curr;
				oddCurr = curr;
			} else {
				oddCurr -> next = curr;
				oddCurr = curr;
			}
		}
	}

	// check if even exists
	if (evenHead !=	NULL) {
		evenCurr -> oddHead;
		return evenCurr
	} else {
		return oddCurr;
	}
}

int main() {
	return 0;
}
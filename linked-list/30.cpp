#include <bits/stdc++.h>
using namespace std;

// delete nodes having greater value on right

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

// Delete nodes having greater value on right
Node* deleteGreaterRight(Node* head) {

	// base case
	if (head == NULL || head -> next == NULL) {
		return head;
	}

	Node* curr = head;

	while(curr -> next != NULL) {

		// delete the current node
		if (curr -> data < curr -> next -> data){
			// copy data from next node to curr node
			// remove next node
			curr -> data = curr -> next -> data;
			curr -> next = curr -> next -> next;
		} else {
			curr = curr -> next;
		}
	}
}

int main() {
	return 0;
}
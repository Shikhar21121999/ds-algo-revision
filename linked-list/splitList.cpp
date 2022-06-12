#include <bits/stdc++.h>
using namespace std;

// split list

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

void splitList(Node* head, Node **head1_ref, Node **head2_ref) {

	// base case
	if (head == NULL) return;

	Node *fast = *slow = head;

	while(fast -> next != head && fast -> next -> next != head) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}

	// if even fast -> next -> next = head
	// move fast forward
	if (fast -> next -> next == head) {
		fast = fast -> next;
	}

	*head_ref = head;

	if (head -> next != head) {
		*head2_ref = slow -> next;
	}

	slow -> next = head1_ref;
	fast -> next = head2_ref;
}

int main() {
	return 0;
}
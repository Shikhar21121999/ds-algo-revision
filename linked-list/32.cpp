#include <bits/stdc++.h>
using namespace std;

// nth node from linked list

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

// nth node from the end of linked list
int getNthFromLast(Node* head, int N) {

	Node *last = nLast = head;

	for (int i = 1; i < n; i++) {
		if (last == NULL) {
			return -1;
		} else {
			last = last -> next;
		}
	}

	while (last -> next != NULL) {
		last = last -> next;
		nLast = nLast -> next;
	}

	return nLast -> data;
	
}

int main() {
	return 0;
}
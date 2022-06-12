#include <bits/stdc++.h>
using namespace std;

// check if linked list is circular

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

int checkCircular (Node* head) {
	Node *curr = head;

	while(curr != NULL && curr -> next != head) {
		curr = curr -> next;
	}
	if (curr -> next == head) {
		return 1;
	} else return 0;
}

int main() {
	return 0;
}
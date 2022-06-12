#include <bits/stdc++.h>
using namespace std;

// Flattening a linked list

class Node {
public:
	int data;
	Node* down;
	Node* right;

	Node () {
		this -> down = NULL;
		this -> right = NULL;
	}

	Node (int data) {
		this -> data = data;
		this -> down = NULL;
		this -> right = NULL;
	}
};

// merge two sorted linked list in increasing order
Node* merge(Node* a, Node* b) {

	if (a == NULL) {
		return b;
	} else if (b == NULL) {
		return a;
	}

	Node* result = NULL;

	if (a -> data < b -> data) {
		result = a;
		result -> down = merge( a-> down, b);
	} else {
		result = b;
		result -> down = flatten(b -> down, a);
	}
	return result;
}

Node* flatten(Node* head) {

	// base case
	if (head == NULL) {
		return head;
	}

	root -> right = flatten(root -> right);
	root = merge(root, root -> right);

	return root;
}

int main() {
	return 0;
}
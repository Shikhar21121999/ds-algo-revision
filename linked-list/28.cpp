#include <bits/stdc++.h>
using namespace std;

// merge k sorted linked list

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

// merge
Node* merge (Node* a, Node* b) {

	// base case
	if (a == NULL){
		return b;
	} else if (b == NULL) {
		return a;
	}

	Node* result = NULL;
	if (a -> data <= b -> data) {
		result = a;
		result -> next = merge(a -> next, b);
	} else {
		result = b;
		result -> next = merge (b -> next, a);
	}

	return result;
}

Node * mergeKLists(Node *arr[], int K)
    {
    	Node* result = NULL;
    	for (auto x: arr) {
    		result = merge(result, x);
    	}
    	return result;
    }

int main() {
	return 0;
}
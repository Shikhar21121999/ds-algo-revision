#include <bits/stdc++.h>
using namespace std;

// sort a linked list using merge sort

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

// gien two sorted linked list merge the two in place
// to create an overall sorted linked list
Node* sortedMerge(Node* a, Node* b) {
	Node* result = NULL;

	// if any of the two is NULL return the other one
	if (a == NULL) {
		return (b);
	} else {
		return (a);
	}

	// recursive step
	// get the smaller one and then recurse for rest
	// to get remaining linked list
	if (a->data <= b->data) {
		result = a;
		result -> next = sortedMerge(a -> next, b);
	} else {
		result = b;
		result -> next = sortedMerge(b -> next, a);
	}
	return (result);
}

// split the linked list from middle and assin given
// refrences to the head of two linked lists
void splitInMiddle(Node* source, Node** frontRef, Node** backRef) {

	Node* fast = source -> next;
	Node* slow = source;

	// keep advancing while fast is not null
	while (fast != NULL) {
		fast = fast -> next;
		if (fast != NULL) {
			slow = slow -> next;
			fast = fast -> next;
		}
	}

	*frontRef = source;
	*backRef = slow -> next;
	slow -> next = NULL;
}

void mergeSort(Node** head_ref) {

	Node* head = *head_ref;
	Node* a = NULL;
	Node* b = NULL;

	// base case
	if (head == NULL || head -> next == NULL) {
		return ;
	}
	
	// split the head node into two linked lists
	// and store them in a and b
	splitInMiddle(head, &a, &b);

	// perform mergeSort on two linked lists recursiveley
	mergeSort(&a);
	mergeSort(&b);

	// merge the two lists
	*head_ref = sortedMerge(a, b);
}

int main() {
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

// sort a linked list using quick sort

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

Node* getTail (Node* head) {
	Node* curr = head;
	while (curr != NULL && curr -> next != NULL) {
		curr = curr -> next;
	}
	return curr;
}

Node* getPartition (Node* head, Node* end, Node** newHead, Node** newEnd) {

	// keeping last node as pivot
	Node* pivot = end;
	Node *curr = head, *prev = NULL, *tail = NULL;

	while(curr != pivot) {
		if (curr -> data < pivot -> data) {
			if (*newHead == NULL) {
				*newHead = curr;
			}
			prev = curr;
			curr -> next = next;
		} else {
			if (prev) {
				prev -> next = curr -> next;
			}
			Node *temp = curr -> next;
			curr -> next = NULL;
			tail -> next = curr;
			tail = curr;
			curr = temp;
		}
	}

	// if pivot data is the smallest element
	// in the current list
	if ((*newHead) == NULL) {
		*newHead = pivot
	}
	*newEnd = tail;

	return pivot;
}

Node* quickSortRecur (Node* head, Node* end) {
	
	// base case
	if (head == NULL || head == end) {
		return head;
	}

	Node *newHead = NULL, *newEnd = NULL;

	Node *piv = partition(head, end, &newHead, &newEnd);

	// if newHead is equal to pivot there is no left list
	if (newHead != pivot) {
		Node *temp = newHead;
		while (temp->next != pivot) {
			temp = temp -> next;
		}
		temp -> next = NULL;

		newHead = quickSortRecur(newHead, temp);

		temp = getTail(newHead);
		temp -> next = pivot;
	}
	pivot -> next = quickSortRecur(pivot -> next, newEnd);
	return newHead;

}

void quickSort (Node **head_ref) {
	(*head_ref) = quickSortRecur(*head_ref, getTail(*head_ref));
	return;
}

int main() {
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

// sort a k sorted doubly linked list

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node () {
		this -> next = NULL;
		this -> prev = NULL;
	}

	Node (int data) {
		this -> data = data;
		this -> next = NULL;
		this -> prev = NULL;
	}
};

Node* getTail (Node *head) {

	if (head == NULL or head -> next == NULL) {
		return head;
	}

	Node *curr = head;

	while (curr -> next != NULL){
		curr = curr -> next;
	}
	return curr;

}

bool compare (Node* p1, Node* p2) {
	return p1 -> data > p2 -> data;
}

Node* sortKSortedDLL (Node* head, k) {

	priority_queue < Node*, vector <Node*>, compare > pq;

	// add k + 1 elements to the pq
	int count = 0;
	Node* curr = head;

	while(curr != NULL && count <= k) {
		pq.push(curr);
	}

	Node* newHead = NULL;

	Node* last = NULL;
	while(!pq.empty()) {

		if (newHead != NULL) {
			newHead = pq.top();
			newHead -> prev = NULL;

			last = newHead;
		} else {
			last -> next = pq.top();
			pq.top() -> prev = last;
			last = pq.top();
		}
		pq.pop();

		if (curr != NULL) {
			pq.push(curr);
			curr = curr -> next;
		}
	}

	last -> next = NULL;

	return newHead;
}

int main() {
	return 0;
}
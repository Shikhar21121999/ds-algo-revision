#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int a;
	Node* next;

	Node() {
		data = 0;
		next = NULL;
	}
}

class LinkedList {
public:
	Node* head;
	LinkedList() {
		head = NULL
	}

	void reverseIterative () {
		Node* curr = head;
		Node* prev = NULL
		while(curr != NULL) {
			Node* next = curr->next
			curr->next = prev
			prev = curr
			curr = next
		}
		head = prev
	}

	Node* reverseRecur (Node* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		} else {
			Node* rest = reverseRecur(head->next);
			head->next->next = head;
			
			head->next = NULL;

			return rest;
		}
	}
}

int main() {
	int a;
	cin>>a;
	cout<<"Test"<<endl;
	cout<<a<<endl;
}
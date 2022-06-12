#include <bits/stdc++.h>
using namespace std;

// check if linked list is palindrome or not

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

Node* reverse (Node *head) {
	if (head == NULL || head -> next == NULL) {
		return head;
	}

	Node *curr = *nxt = head;
	Node *prev = NULL;

	while (curr != NULL) {
		nxt = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = nxt;
	}
	return prev;

}

// in case of even returns first element
Node* getMiddle (Node* head) {
	Node *slow = *fast = head;

	while(fast -> next != NULL && fast -> next -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}

	return slow;

}

// reverse the second half of the list
// then traverse and check if pallindrome
int isPallindrome (Node* head) {
	
	// base case
	if (head == NULL || head -> next == NULL) {
		return 1;
	}

	Node* mid = getMiddle(head);

	Node* sec_half = reverse(mid -> next);

	Node *curr1 = head;
	Node *curr2 = sec_half;

	int ans = 1;
	while(curr1 != NULL && curr2 != NULL) {
		if (curr1 -> data != curr2 -> data) {
			ans	= 0;
		}
		curr1 = curr1 -> next;
		curr2 = curr2 -> next;
	}

	// restore the original list
	Node *sec_half = reverse(sec_half);
	mid -> next = sec_half;

	return ans;

}



int main() {
	return 0;
}
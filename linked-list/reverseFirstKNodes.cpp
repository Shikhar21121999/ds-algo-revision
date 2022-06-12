#include <bits/stdc++.h>
using namespace std;

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

Node* reverse(Node* head, int k) {

	// base case
	if (head == NULL) {
		return NULL;
	}
	// reverse first k nodes
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;
	int count = 0;

	while(curr != NULL && count < k) {
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
		count += 1;
	}

	// imagine and check the position of prev, curr and next after k iterations

	head -> next = reverse(next, k);

	// prev is the new head of the linked list
	return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main () {
	Node* head = NULL;
	/* Created Linked list
       is 1->2->3->4->5->6->7->8->9 */
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given linked list \n";
    printList(head);
    head = reverse(head, 3);
 
    cout << "\nReversed Linked list \n";
    printList(head);
 
    return (0);
}
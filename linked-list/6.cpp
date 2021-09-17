#include <bits/stdc++.h>
using namespace std;

// move last element to the first of the linked list
// 1->2->3->4 input
// 4->1->2->3 output

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

Node* moveToFirst (Node* head) {
	if (head == NULL || head -> next == NULL) {
		return head;
	}
	Node* sec_last = head;
	Node* last = head -> next;

	while(last -> next != NULL) {
		sec_last = sec_last -> next;
		last = last -> next;
	}
	sec_last -> next = NULL;
	last -> next = head;
	head = last;
	return head;
}

/* UTILITY FUNCTIONS */
/* Function to create a circular linked list */
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

int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    push(&head, 20);
    push(&head, 15);
    push(&head, 10);
    push(&head, 4);

 
    /* Create a loop for testing */
    printList(head);
    cout<<endl;
    Node* nhead = moveToFirst(head);
    printList(nhead);
    return 0;
}
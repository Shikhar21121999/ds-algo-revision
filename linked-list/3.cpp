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

int detectLoop (Node* head) {
	Node* slow = head;
	Node* fast = head;

	while(slow != NULL && fast != NULL && fast -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
		if (slow == fast) {
			return 1;
		}
	}
	return 0;
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
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    // head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}
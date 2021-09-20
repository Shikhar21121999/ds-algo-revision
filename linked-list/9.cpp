#include <bits/stdc++.h>
using namespace std;

// find and return the intersection of two sorted linked lists

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

	while(curr != NULL) {
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

int length_linked_list(Node* head) {
	int len = 0;
	Node* curr = head;

	while(curr != NULL) {
		len++;
		curr = curr -> next;
	}
	return len;

}

Node* sortedIntersect (Node* head1, Node* head2) {
	Node* curr1 = head1;
	Node* curr2 = head2;
	Node* head3 = new Node();
	Node* curr3 = NULL;

	while(curr1 != NULL && curr2 != NULL) {

		if (curr1 -> data == curr2 -> data) {
			if (curr3 == NULL) {
				head3-> data = curr1 ->data;
				curr3 = head3;
			} else if (curr1 -> data != curr3 -> data){
				Node* new_node = new Node(curr1 -> data);
				curr3 -> next = new_node;
			}
			curr1 = curr1 -> next;
			curr2 = curr2 -> next;
			curr3 = curr3 -> next;
		} else if(curr1 -> data < curr2 ->data) {
			curr1 = curr1 -> next;
		} else  {
			curr2 = curr2 -> next;
		}
	}
	return head3;
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
    Node* head1 = NULL;

    push(&head1, 15);
    push(&head1, 10);
    push(&head1, 9);
    push(&head1, 9);
    push(&head1, 8);
    push(&head1, 4);

    Node* head2 = NULL;
 
    push(&head2, 15);
    push(&head2, 9);
    push(&head2, 8);
    push(&head2, 4);

    printList(head1);
    cout<<endl;
    printList(head2);
    cout<<endl;
 	Node* head3 = sortedIntersect(head1, head2);
 	printList(head3);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// remove duplicates from a un-sorted linked list

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
		cur=r = next;
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

// Add two linked list
void addLinkedList(Node* head1, Node* head2) {

	// reverse the two linked list
	Node* rev_head1 = reverse(head1);
	Node* rev_head2 = reverse(head2);

	// get length of two linked list
	int len1 = rev_head1;
	int len2 = rev_head2;

	Node* curr1 = rev_head1;
	Node* curr2 = rev_head2;

	if (len1 < len2) {
		curr1 = rev_head2;
		curr2 = rev_head1;
	}

	while(curr2 != NULL) {
		curr1 -> data = curr1 -> data + curr2 -> data;
		curr1 = curr1 -> next;
		curr2 = curr2 -> next;
	}

	Node* curr = rev_head1;

	int carry = 0;
	while(curr != NULL) {
		curr -> data = curr -> data + carry;

		if (curr -> data > 10) {
			carry =1;
			curr -> data = curr -> data - 10;
		} else {
			carry = 0;
		}
		curr = curr -> next;
	}

	// reverse the sum
	Node* head = reverse(rev_head1);

	// check if extra node needs to be added
	if (carry == 1) {
		Node* new_node = Node(1);
		new_node -> next = head;
		head = new_node;
	}

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
 
    push(&head, 9);
    push(&head, 9);
    // push(&head, 8);
    // push(&head, 15);
    // push(&head, 10);
    // push(&head, 4);

 
    /* Create a loop for testing */
    printList(head);
    cout<<endl;
    Node* nhead = addOne(head);
    printList(nhead);
    return 0;
}
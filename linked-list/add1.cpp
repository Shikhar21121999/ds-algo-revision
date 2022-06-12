#include <bits/stdc++.h>
using namespace std;

// add 1 to a linked list which represent a number

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

// method
// key point => 9 is of the utmost importance
// sum will not be carried forward beyond a node which is not 9
// find the rightmost node which is not 9
// consider three conditions 
// 1. there is no non_nine node
// 2. this non_nine node is the last node of ll
// 3. non_nine node exist in middle of ll

Node* addOne (Node* head) {

	Node* last = NULL;
	Node* curr = head;

	while(curr -> next != NULL){
		if (curr -> data != 9) {
			last = curr;
		}
		curr = curr -> next;
	}

	if (last == NULL) {
		// cout<<"last aaya none";
		Node* new_node = new Node(0);
		new_node -> next = head;
		head = new_node;
		last = head;
	}
	else if (curr -> data != 9) {
		curr -> data ++;
		return head;
	}
	last -> data += 1;
	last = last -> next;

	while(last != NULL) {
		last -> data = 0;
		last = last -> next;
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
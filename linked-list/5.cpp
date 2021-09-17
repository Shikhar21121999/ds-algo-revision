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

Node* removeDuplicates (Node* head) {
	Node* curr = head;
	Node* prev = head;
	unordered_set <int> dict;

	if (head == NULL || head->next == NULL) {
		return head;
	}
	dict.insert(head -> data);
	curr = head -> next;

	while(curr != NULL) {
		if (dict.find(curr -> data) == dict.end()) {
			prev -> next = curr;
			prev = curr;
			dict.insert(curr -> data);
		}
		curr = curr -> next;
	}
	prev -> next = curr;

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
    push(&head, 10);
    push(&head, 15);
    push(&head, 15);
    push(&head, 10);
    push(&head, 4);

 
    /* Create a loop for testing */
    printList(head);
    cout<<endl;
    Node* nhead = removeDuplicates(head);
    printList(nhead);
    return 0;
}
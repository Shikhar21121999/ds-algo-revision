#include <bits/stdc++.h>
using namespace std;

// first node of loop in a linked list

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

// method 1
// floyd's loop detection 
// first check for the loop
// the point where slow and fast meet, make fast slow now
// and make slow to point to head
// start traversing and the point where fast and slow meet
// is the first node

Node* detectLoopOrigin (Node* head) {
	Node* slow = head;
	Node* fast = head;

	while(slow != NULL && fast != NULL && fast -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
		if (slow == fast) {
			// loop found
            break;
		}
	}

    if (slow != fast) {
        return NULL;
    }

    slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}

// method 2
// create an extra node (temp), keep pointing each traversed node
// to this temp node, whenever you encounter a node that is already
// pointing to the temp node, a loop is found and the curr node is the
// origing point of the node

// method 3: hashing
// create a set and or hash map and keep storing the address of the nodes
// whenever a node is found whose address already exists then there is a loop
// and current node is the starting point of the node

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
    head->next->next->next->next = head;
    Node* orig = detectLoopOrigin(head);
    if (orig != NULL) {
        cout << "Loop found";
        cout << orig -> data;
    }
    else
        cout << "No Loop";
    return 0;
}
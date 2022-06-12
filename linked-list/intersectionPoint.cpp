#include <bits/stdc++.h>
using namespace std;

// find and return the intersection point of two linked list in Y shape

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

Node* getIntersectionNode(Node* head1, Node* head2, int d) {

	Node* curr1 = head1;
	Node* curr2 = head2;

	// move the pointer forward
	for (int i=0; i < d; i++){
		if (curr1 == NULL) return NULL;
		curr1 = curr1 -> next;
	}

	while(curr1 != NULL && curr2 != NULL){
		if (curr1 == curr2) return curr1;
		curr1 = curr1 -> next;
		curr2 = curr2 -> next;
	}

	return NULL;

}

Node* findIntersectionPoint (Node* head1, Node* head2) {
	int len1 = length_linked_list(head1);
	int len2 = length_linked_list(head2);
	

	int diff = abs(len1 - len2);

	if (len1 > len2) {
		return getIntersectionNode(head1, head2, diff);
	} else {
		return getIntersectionNode(head2, head1, diff);
	}
}

// A utility function to return  intersection node
Node* intersectPoint(Node* head1, Node* head2)
{
    // Maintaining two pointers ptr1 and ptr2
    // at the head of A and B,
    Node* ptr1 = head1;
    Node* ptr2 = head2;
 
    // If any one of head is NULL i.e
    // no Intersection Point
    if (ptr1 == NULL || ptr2 == NULL)
        return NULL;
 
    // Traverse through the lists until they
    // reach Intersection node
    while (ptr1 != ptr2) {
 
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
 
        // If at any node ptr1 meets ptr2, then it is
        // intersection node.Return intersection node.
 
        if (ptr1 == ptr2)
            return ptr1;
        /* Once both of them go through reassigning,
        they will be equidistant from the collision point.*/
 
        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL)
            ptr1 = head2;
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL)
            ptr2 = head1;
    }
    return ptr1;
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
    return 0;
}
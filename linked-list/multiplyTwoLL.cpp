#include <bits/stdc++.h>
using namespace std;

// multiply two linked list

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

// multiply two linked list
long long multiplyTwoLinkedList(Node *a, Node *b) {

	long long N= 1000000007;
    long long num1 = 0, num2 = 0;

    while(a != NULL || b != NULL) {
    	if (a != NULL) {
    		num1 = (num1*10)%N + num1 -> data;
    		a = a -> next;
    	}
    	if (b != NULL) {
    		num2 = (num2*10)%N + num2 -> data;
    		b = b -> next;
    	}
    }

    return ((num1%N)* (num2%N));
}

int main() {
	return 0;
}
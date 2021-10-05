#include <bits/stdc++.h>
using namespace std;

// reverse level order traversal

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node() {
		this -> data = 0;
		this -> left = NULL;
		this -> right = NULL;
	}

	Node (int a) {
		this -> data = a;
		this -> left = NULL;
		this -> right = NULL;
	}
};

void reverseLevelOrderTraversal(Node *root) {
	queue <Node *> q;
	stack <Node *> st;
	q.push(root);

	while(!q.empty()) {
		Node *curr = q.front();
		st.push(curr);
		q.pop();

		if (curr -> right) {
			q.push(curr -> right);
		} if (curr -> left) {
			q.push(curr -> left);
		}
	}

	while(!st.empty()) {
		cout << st.top() -> data << " ";
		st.pop();
	}
}

int main() {
	// create binary tree
	Node *root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);
	reverseLevelOrderTraversal(root);
}
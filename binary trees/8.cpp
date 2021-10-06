#include <bits/stdc++.h>
using namespace std;

// Post order traversal of binary tree
// Left right root

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node() {
		this -> data = 0;
		this -> left = nullptr;
		this -> right = nullptr;
	}

	Node (int a) {
		this -> data = a;
		this -> left = nullptr;
		this -> right = nullptr;
	}
};

void postorderRecursive (Node* root) {

	// base case
	if (root == nullptr) return;

	// recurse for left subtree
	postorderRecursive(root -> left);
	
	// recruse for right subtree
	postorderRecursive(root -> right);

	// visit node
	cout << root -> data << " ";
}

void postorderIterative (Node* root) {

	stack <Node *> st;
	stack <Node *> out;
	if (root == nullptr) return;

	st.push(root);

	while(!st.empty()) {
		Node *curr = st.top();
		st.pop();
		out.push(curr);

		if (curr -> left != nullptr) {
			st.push(curr -> left);
		}
		
		if (curr -> right != nullptr) {
			st.push(curr -> right);
		}

	}

	while(!out.empty()) {
		Node *curr = out.top();
		out.pop();
		cout << curr -> data << " ";
	}
}



int main() {
	// create binary tree
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	postorderIterative(root);
}
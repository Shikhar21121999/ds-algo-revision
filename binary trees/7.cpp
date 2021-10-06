#include <bits/stdc++.h>
using namespace std;

// Preorder traversal of Binary Tree
// Root -> Left -> Right

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

void preorderRecursive (Node* root) {

	// base case
	if (root == nullptr) return;

	// visit node
	cout << root -> data << " ";

	// recurse for left subtree
	preorderRecursive(root -> left);
	
	// recruse for right subtree
	preorderRecursive(root -> right);
}

void preorderIterative (Node* root) {

	stack <Node *> st;
	if (root == nullptr) return;

	st.push(root);

	while(!st.empty()) {
		Node *curr = st.top();
		st.pop();
		cout << curr -> data << " ";

		if (curr -> right != nullptr) {
			st.push(curr -> right);
		}
		if (curr -> left != nullptr) {
			st.push(curr -> left);
		}
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
#include <bits/stdc++.h>
using namespace std;

// Inorder Traversal of Binary Tree
// Left -> Root -> Right

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

void inorderRecursive(Node *root) {
	if (root == nullptr) return;

	// recurse left
	inorderRecursive(root -> left);

	// print current
	cout << root -> data << " ";

	// recurse right
	inorderRecursive(root -> right);
}

void inorderIterative(Node* root) {
	stack <Node *> st;

	Node* curr = root;
	while(!st.empty() or curr != nullptr) {
		if (curr != nullptr) {
			st.push(curr);
			curr = curr -> left;
		} else {
			curr = st.top();
			st.pop();

			cout << curr -> data << " ";

			curr = curr -> right;
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
	inorderIterative(root);
}
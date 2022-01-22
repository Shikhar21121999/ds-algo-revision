#include <bits/stdc++.h>
using namespace std;

// Mirror of a tree

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

Node* reflect(Node* root) {
	if (root == nullptr or (root -> left == nullptr and root -> right == nullptr)) {
		return root;
	} else {
		Node *leftRef = reflect(root -> left);
		Node *rightRef = reflect(root -> right);

		root -> left = rightRef;
		root -> right = leftRef;
		return root;
	}
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
	Node *root = new Node(5);
	root -> left = new Node(3);
	root -> right = new Node(6);
	root -> left -> left = new Node(2);
	root -> left -> right = new Node(4);
	inorderIterative(root);
	cout <<endl;
	Node* refroot = reflect(root);
	inorderIterative(refroot);
}
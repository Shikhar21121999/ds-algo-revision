#include <bits/stdc++.h>
using namespace std;


// Zig-Zag traversal of a binary-tree

class Node{
public:
	int data;
	Node* left;
	Node* right;
	int hd;

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

void zigZag(Node *root) {
	if (Node == nullptr) {
		return;
	}

	queue <Node *> q;

	cout >> root -> data;
	q.push(root);

	while(!q.empty()) {
		Node *curr = q.front();
		q.pop()
		cout << root -> right -> data << " " << root -> left -> data;
		if (root -> left != nullptr) {
			q.push(root -> left);		
		}
		if (root -> left != nullptr) {
			q.push(root -> right);	
		}
	}
	return;
}

int main() {
	// create binary tree
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	vector <int> result = rightView(root);
	for (auto x: result) {
		cout << x << " ";
	}
}
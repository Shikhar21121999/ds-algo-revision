#include <bits/stdc++.h>
using namespace std;

// Top view of a binary tree is the set of nodes visible when the tree is viewed from the top

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
		this -> hd = 0;
	}

	Node (int a) {
		this -> data = a;
		this -> left = nullptr;
		this -> right = nullptr;
		this -> hd = 0;
	}
};

void topView (Node* root) {

	if (root == nullptr) return;

	queue < Node* > q;
	map <int, int> m;

	int hd = 0;
	root -> hd = hd;

	while(q.size()) {
		hd = root -> hd;

		if (m.count(hd) == 0) {
			m[hd] = root -> data;
		}
		if (root -> left) {
			root -> left -> hd = hd - 1;
			q.push(root -> left);
		} if (root -> right) {
			root -> right -> hd = hd + 1;
			q.push(root -> right);
		}
		q.pop();
		root = q.front();
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it -> second;
	}
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
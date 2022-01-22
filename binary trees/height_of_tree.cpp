#include <bits/stdc++.h>
using namespace std;

// height of binary tree

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

int heightOfTree(Node *root) {
	if (root == nullptr) {
		return -1;
	}

	int ltree = 0, rtree = 0;
	ltree = heightOfTree(root -> left);
	rtree = heightOfTree(root -> right);

	return 1 + max(ltree, rtree);
}

int main() {
	// create binary tree
	Node *root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);
	heightOfTree(root);
}
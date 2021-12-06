#include <bits/stdc++.h>
using namespace std;

// Diameter of a binary tree

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

void heightOfTree(Node *root) {
	if (root == nullptr) {
		return -1;
	}

	int ltree = rtree = 0;
	ltree = heightOfTree(root -> left);
	rtree = heightOfTree(root -> right);

	return 1 + max(ltree, rtree);
}

int diameterTree(Node *root) {

	// base case
	if (root == nullptr) return 0;

	int lTreeDia = rTreeDia = 0;
	// diameter through the root
	int selfDia = heightOfTree(root -> left) + heightOfTree(root -> right) + 1;

		lTreeDia = diameterTree(root -> left);
		rTreeDia = diameterTree(root -> right);

	return max(rTreeDia, max(selfDia,lTreeDia));
	
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
#include <bits/stdc++.h>
using namespace std;


// check if tree is balanced

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

int heightOfTree(Node *root) {
	if (root == nullptr) return 0;

	return 1 + max(heightOfTree(root -> left), heightOfTree(root -> right));
}

bool isBalanced(Node *root) {

	// base case
	if (root == nullptr) return true;

	return isBalanced(root -> left) && isBalanced(root -> right) && abs(heightOfTree(root -> left) - heightOfTree(root -> right)) <= 1;
}

bool isBalancedOptimized(Node *root, int *height) {
	int lh = rh = 0;

	if (root == nullptr) {
		*height = 0;
		return true;
	}

	bool l = isBalancedOptimized(root -> left, &lh);
	bool r = isBalancedOptimized(root -> right, &rh);

	*height = max(lh, rh) + 1;

	return l && r && abs(lh - rh) <= 1; 
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
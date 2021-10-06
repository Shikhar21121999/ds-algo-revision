#include <bits/stdc++.h>
using namespace std;

// Left view of a Binary Tree is set of nodes visible 
// when tree is visited from Left side.

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

vector<int> leftView(Node *root) {
	Node *curr = root;

	vector <int> a;
	// base case
	if (root == nullptr) return a;

	queue <Node *> q;

	q.push(curr);
	while(!q.empty()) {
		Node *curr = q.front();
		q.pop();
		a.push_back(curr -> data);

		if (curr -> left) {
			q.push(curr -> left);
		} else if (curr -> right) {
			q.push(curr -> right);
		}
	}
	return a;

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

	vector <int> result = leftView(root);
	for (auto x: result) {
		cout << x << " ";
	}
}
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node() {
		this -> data = 0;
		this -> left = NULL;
		this -> right = NULL;
	}

	Node (int a) {
		this -> data = a;
		this -> left = NULL;
		this -> right = NULL;
	}
};

void LevelOrderTraversal (Node* root) {

	queue < Node* > q;
	q.push(root);

	while(!q.empty()) {
		Node* curr = q.front();
		cout<<curr -> data<<" ";
		q.pop();
		if (curr -> left != NULL) {
			q.push(curr -> left);
		} if (curr -> right != NULL) {
			q.push(curr -> right);
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
	LevelOrderTraversal(root);
}
#include <bits/stdc++.h>
using namespace std;

// print a binary tree in vertical order 

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

void printVerticalOrder(Node *root) {
	if (!root) return;

	unordered_map <int, vector <int> > m;
	int hd = 0;

	queue <pair <Node*, int> > q;
	q.push({root, hd})

	int mn = 0, mx = 0;

	while(!q.empty()) {
		pair <Node*, int> curr = q.front();
		q.pop();
		hd = curr.second;
		Node *node = curr.first;

		m[hd].push_back(node -> data);

		if (node -> left) {
			q.push({node -> left, hd - 1});
		} if (node -> right) {
			q.push({node -> right, hd + 1});
		}

		// update mn and mx
		if (mn > hd) {
			mn = hd;
		} if (mx < hd) {
			mx = hd;
		}
	}

	// for each hd get the data from stored map
	for (int i=mn; i <= mx; i++) {
		for (auto x: m[i]) {
			cout << x << " ";
		}
		cout << endl;
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
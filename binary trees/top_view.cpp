#include <bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define pii pair <int, int>
# define vpii vector<pii>
// Top view of binary tree without modification to tree

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

/*
Approach is to store the horizontal distance of each node
from the center of tree (root) while recursing using a hash map
At the convert the hash map to vpii and sort it
create a vector from the second element of vpii and return
*/

void recur(Node* root, int hd, unordered_map <int, int> &recd) {
    if (recd[hd] == 0) {
		recd[hd] = root -> data;
	}
	if (root -> left != nullptr) {
		recur(root -> left, hd - 1, recd);
	}
	if (root -> right != nullptr) {
		recur(root -> right, hd + 1, recd);
	}
}

vector <int> topView(Node *root) {
    // base case
	vector <int> ans;
	unordered_map < int, int > recd;
    if (root == nullptr) return ans;
	recur(root, 0, recd);

	// now in unordered map we have a root -> data assigned for each hd
	// convert it into vpii and sort it
	vpii sort_arr;
	for (auto x: recd) {
		sort_arr.push_back(x);
	}

	sort(sort_arr.begin(), sort_arr.end());

	for (auto x: sort_arr) {
		ans.push_back(x.second);
	}
	return ans;

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

}
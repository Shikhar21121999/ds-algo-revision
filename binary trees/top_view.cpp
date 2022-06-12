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

/*
possible improvement is to calculate smallest and greatest hd
all the hd will be in between in these both inclusive thus we can
save sorting by running and collecting values using a simple for loop
*/

vector <int> topView(Node *root) {
    // base case
	vector <int> ans;
	unordered_map < int, int > recd;
    if (root == nullptr) return ans;

	// use queue for bfs
	queue <pair <Node*, int> > q;
	q.push({root, 0});

	int smHd = 1;
	int maxHd = -1;

	while (!q.empty()) {
		Node* curr = q.front().first;
		int hd = q.front().second;

		q.pop();

		if (recd.find(hd) == recd.end()) {
			recd[hd] = curr -> data;
			smHd = min(smHd, hd);
			maxHd = max(maxHd, hd);
		}

		// push left and right nodes
		if (root -> left != NULL) {
			q.push({root -> left, hd - 1});
		}

		if (root -> right != NULL) {
			q.push({root -> right, hd + 1});
		}
	}

	for (int i = smHd; i <= maxHd; i++) {
		ans.push_back(recd[i]);
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
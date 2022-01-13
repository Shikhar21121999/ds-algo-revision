#include <bits/stdc++.h>
using namespace std;

// Post order traversal of binary tree
// Left right root

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

void postorderRecursive (Node* root) {

	// base case
	if (root == nullptr) return;

	// recurse for left subtree
	postorderRecursive(root -> left);
	
	// recruse for right subtree
	postorderRecursive(root -> right);

	// visit node
	cout << root -> data << " ";
}

// two stack
void postorderIterative (Node* root) {

	stack <Node *> st;
	stack <Node *> out;
	if (root == nullptr) return;

	st.push(root);

	while(!st.empty()) {
		Node *curr = st.top();
		st.pop();
		out.push(curr);

		if (curr -> left != nullptr) {
			st.push(curr -> left);
		}
		
		if (curr -> right != nullptr) {
			st.push(curr -> right);
		}

	}

	while(!out.empty()) {
		Node *curr = out.top();
		out.pop();
		cout << curr -> data << " ";
	}
}

/*
	A bit hard to understand, for understanding please follow comments
	along with basic approach to solve the question
	we use stack to emulate recursion along with implementation
	to support the required flow
*/
void postorderIterative1 (Node *root) {
	vector <int> postOrder; // stores the result

	stack <Node*> st;
	Node *curr = root;

	// curr is the pointer to the node or even nullptr if required
	while (curr != nullptr or !st.empty()) {
		if (curr != nullptr) {
			st.push(curr); // push curr in stack
			curr = curr -> left; // first recurse for left subtree
		} else {
			// here curr is nullptr curr does not have left or right
			// get the node from stack
			// this is a node whose left is visited
			Node* ancestor = st.top();
			// now either this nodes has a right subtree (unvisited) and needs to be visited
			if (ancestor -> right != nullptr) {
				curr = ancestor -> right;
			} else {
				// or this node does not have a right subtree
				// in this particular case we get that left subtree for ancestor is visited and right subtree for ancestor does not exist
				// hence we need to just visit the node
				postOrder.push_back(ancestor -> data);
				st.pop();
				// now there is a possibility of having a tree like this
				/*
					1
						2
							3
								4
				basically right right right
				*/
				// we will try to visit all such ancestor nodes in one sweep
				while(!st.empty() && ancestor == st.top() -> right) {
					ancestor = st.top(); st.pop();
					postOrder.push_back(ancestor -> data);
				}
			}
		}
	}
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

	postorderIterative(root);
}
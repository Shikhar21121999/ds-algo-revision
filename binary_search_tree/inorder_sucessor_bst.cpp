#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode () {
            this -> val = 0;
            this -> left = nullptr;
            this -> right = nullptr;
        }
        TreeNode (int data) {
            this -> val = data;
            this -> left = nullptr;
            this -> right = nullptr;
        } 
};

/*
Method 1:
Store the Inorder of the tree in a vector
find the first element that comes after the node
we can use binary search to find the val just greater
than the node in the vector since it is sorted
*/

/*
Method 2:
Perform inorder traversal and get the next node after the reqd node
*/

/*
Look for a node just greater than the current node
int the bst, using bst property
*/

// find the element just greater than root
// if current element < required element
// search in right
// if current element > required element // element just greater
// possible answer mark
// it is still possible to find an element such that it is lesser than this element
// but greater than required in that case it will be the answer

TreeNode* inorderSucessor(TreeNode *root, TreeNode *p) {
    TreeNode *successor = nullptr;

    while (root != nullptr) {
        if (root -> val <= p -> val) {
            root = root -> right;
        } else {
            successor = root;
            root = root -> left;
        }
    }
    return successor;
    
}

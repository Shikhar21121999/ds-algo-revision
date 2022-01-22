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

TreeNode* inorderSucessor(TreeNode *root, TreeNode *p) {
    TreeNode *predecessor = nullptr;

    while (root != nullptr) {
        if (root -> val >= p -> val) {
            root = root -> left;
        } else {
            predecessor = root;
            root = root -> right;
        }
    }
    return predecessor;
    
}

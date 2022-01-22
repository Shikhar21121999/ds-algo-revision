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
Approach is to simply get sorted array from bst using inorder traversal
then use that sorted array to create a balanced bst
as done in sorted_arr_bst.cpp
*/

vi inorderIterative(TreeNode *root) {
    stack < TreeNode* > st;
    TreeNode *curr = root;
    vi ans;

    while(!st.empty() or curr != nullptr) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr -> left;
        } else {
            curr = st.top();
            st.pop();
            ans.push_back(curr -> val);
            curr = curr -> right;
        }
    }
    return ans;
}

TreeNode* createBst(vi &nums, int left, int right) {
    // base case
    if (left == right) {
        return nullptr;
    }
    if (right - left == 1) {
        return new TreeNode(nums[left]);
    }

    // recursive case
    int mid = left + (right - left)/2;
    TreeNode *root = new TreeNode(nums[mid]);
    root -> left = createBst(nums, left, mid);
    root -> right = createBst(nums, mid + 1, right);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    // base case leaf node
    if (root -> left == nullptr and root -> right == nullptr) {
        return root;
    }

    // get sorted array for the tree
    vi sortedArr = inorderIterative(root);

    // create a balanced bst from the sorted array
    return createBst(sortedArr, 0, sortedArr.size());
}

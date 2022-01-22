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

// left is inclusive and right is exclusive here
TreeNode* recur(vi &nums, int left, int right) {
    // base case
    if (left == right) return nullptr;
    if (left - right == 1) {
        return new TreeNode(nums[left]);
    }

    // recursive case
    int mid = left + (right - left)/2;

    TreeNode *root = new TreeNode(nums[mid]);
    root -> left = recur(nums, left, mid);
    root -> right = recur(nums, mid+1, right);
    return root;
}

// abstract function to create BST from sorted array nums
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return recur(nums, 0, nums.size());
}
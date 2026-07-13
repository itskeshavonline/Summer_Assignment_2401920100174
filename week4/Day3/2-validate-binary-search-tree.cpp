/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool validate(TreeNode* root, long long minVal, long long maxVal) {
        // An empty tree/leaf child is always a valid BST
        if (root == nullptr) return true;

        // Check if the current node violates the global boundry
        if (root->val <= minVal || root->val >= maxVal) return false;

        // Go left: update upper bound to root->val
        // Go right: update lower bound to root->val
        return validate(root->left, minVal, root->val) && 
               validate(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};
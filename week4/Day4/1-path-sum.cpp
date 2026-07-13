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
    bool path(TreeNode* root , int sum, int targetSum) {
        if (root == nullptr) return false;

        sum += root->val;

        // Only check the sum if we are at an actual LEAF node
        if (root->left == nullptr && root->right == nullptr) {
            return sum == targetSum;
        }

        bool left = path(root->left, sum, targetSum);
        if (left == true) return true;

        bool right = path(root->right, sum, targetSum);
        if (right == true) return true;

        return false; // If neither path worked
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return path(root, sum, targetSum);
    }
};
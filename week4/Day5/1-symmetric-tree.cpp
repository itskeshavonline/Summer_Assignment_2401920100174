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
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Base case: both are empty, so they match
        if (t1 == nullptr && t2 == nullptr) return true;
        
        // One is empty and the other isn't, so they don't match
        if (t1 == nullptr || t2 == nullptr) return false;
        
        // The values must match, 
        // AND their structural mirrors must match(inside to inside and outside to outside)
        return (t1->val == t2->val)
            && isMirror(t1->left, t2->right)
            && isMirror(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};
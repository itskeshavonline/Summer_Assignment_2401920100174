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
public:
    int diameter = 0;

    int height(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        // diameter of binary tree = leftheight + rightheight
        diameter = max(diameter, leftHt + rightHt);

        return 1 + max(leftHt, rightHt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return diameter;
    }
};
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
    int globalMaxSum;

    int calculateGain(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        // Step 1 & 2: the max path of left and right subtrees.
        // If the path sum is negative, ignore it by max(0, ...).
        int leftGain = max(0, calculateGain(root->left));
        int rightGain = max(0, calculateGain(root->right));

        // Step 3: Calculate the max sum of the path passing through the current node as the peak (Arch).
        int currentArchSum = root->val + leftGain + rightGain;

        // Update global max sum if this arch is better.
        globalMaxSum = max(globalMaxSum, currentArchSum);

        // Step 4: Return the maximum straight branch sum to the parent node.
        return root->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        globalMaxSum = INT_MIN; // Initialize with the lowest possible value
        calculateGain(root);
        return globalMaxSum;
    }
};
// it is post order traversal because we need to calculate the max path sum of left and right subtrees before calculating the max path sum of the current node.
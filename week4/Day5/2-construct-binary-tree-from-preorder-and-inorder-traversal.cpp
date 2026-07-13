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
    unordered_map<int, int> inorderMap;
    int preorderIndex;

    TreeNode* arrayToTree(const vector<int>& preorder, int left, int right) {
        // left and right to mark the boundaries of the current inorder slice.
        // Base case: if there are no elements to construct the subtree
        if (left > right) return nullptr;

        // Select the preorderIndex element as the root and increment it
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Build left and right subtrees based on the root's split point in inorder array
        int inorderRootIndex = inorderMap[rootValue];

        // Crucial: build left subtree first
        root->left = arrayToTree(preorder, left, inorderRootIndex - 1);
        root->right = arrayToTree(preorder, inorderRootIndex + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        inorderMap.clear();
        
        // hashmap to store value -> index relations for inorder array and TC:O(1)
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, inorder.size() - 1);
    }
};
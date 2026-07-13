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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> values;
        if (root == nullptr) return values;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; // Flag to track direction

        while (!q.empty()) {
            int levelSize = q.size(); // total nodes in the current level
            vector<int> temp(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                // If leftToRight is true, fill normally. Otherwise, fill temp from the back.
                int index = leftToRight ? i : (levelSize - 1 - i);
                temp[index] = current->val;

                if (current->left != nullptr) q.push(current->left);
                if (current->right != nullptr) q.push(current->right);
            }

            values.push_back(temp);
            leftToRight = !leftToRight; // change the direction for the next level
        }

        return values;
    }
};
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
    queue<TreeNode*> q;
    vector<vector<int>> values;
    vector<int> temp;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return values;

        q.push(root);
        q.push(nullptr); // initial level marker

        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if(current == nullptr) { //current level is finished
                values.push_back(temp);
                temp.clear();

                // If the queue is not empty,
                // it means children of the next level are already pushed,
                // so we place a new marker for that next level
                if(!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                temp.push_back(current -> val);

                if (current->left != nullptr) {
                    q.push(current->left); // Push left child
                }
                if (current->right != nullptr) {
                    q.push(current->right); // Push right child
                }

            }
        }
        return values;
    }
};
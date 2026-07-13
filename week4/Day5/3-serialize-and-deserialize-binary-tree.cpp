/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    // Helper function for serialization (Preorder Traversal)
    void serializeHelper(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "# ";
            return;
        }
        s += to_string(root->val) + " ";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    // Helper function for deserialization
    TreeNode* deserializeHelper(const string& data, int& pos) {
        if (pos >= data.length()) {
            return nullptr;
        }

        int next_space = data.find(' ', pos); 
        // searches for the very first space character ' ' , starting the search from the position pos
        string token = data.substr(pos, next_space - pos); 
        // data.substr(start_index, length) cuts a small piece out of the string.
        pos = next_space + 1; // Automatically reads up to the next space character

        if (token == "#") {
            return nullptr;
        }

        // Convert string token back to integer and create node
        TreeNode* root = new TreeNode(stoi(token));
        
        // Rebuild subtrees sequentially (Order matters: Left then Right)
        root->left = deserializeHelper(data, pos);
        root->right = deserializeHelper(data, pos);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
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

class Codec {
private:
    void serializeHelper(TreeNode* root, string& res) {
        if (root == nullptr) {
            res += "#,";
            return;
        }

        // Root -> Left -> Right
        res += to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }

    TreeNode* deserializeHelper(stringstream& ss) {
        string token;
        if (!getline(ss, token, ',') || token == "#") {
            return nullptr;
        }

        // Root -> Left -> Right
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

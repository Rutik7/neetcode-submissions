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
#include <cstring>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#,";
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr)
            {
                res += "#,";
                continue;
            }

            else
            {
                res += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }

        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data == "#" || data == "#,") return nullptr;


        char* token = strtok(&data[0],",");
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            // left child
            token = strtok(nullptr,",");

            // check if token is valid
            if(token != nullptr && token[0] != '#')
            {
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            }

            // right child
            token = strtok(nullptr,",");
            if(token != nullptr && token[0] != '#')
            {
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            }
        }

        return root;





    }
};

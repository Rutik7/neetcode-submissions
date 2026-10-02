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
    bool helper(TreeNode* root, int& height)
    {
        if(root == nullptr)
        {
            height = 0;
            return true;
        }

        int leftheight = 0;
        int rightheight = 0;

        // Recurse on left and right subtree for height and balanced
        bool leftBalanced = helper(root->left,leftheight);
        bool rightBalanced = helper(root->right,rightheight);

        //compute current node's height
        height = 1 + max(leftheight,rightheight);

        if(!leftBalanced || !rightBalanced) return false;

        return abs(leftheight - rightheight) <= 1;

    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return helper(root,height);
    }
};
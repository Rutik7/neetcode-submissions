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
    int maxDepth(TreeNode* root, int& diameter)
    {
        if(root == nullptr) return 0;
        
        int leftdepth = maxDepth(root->left,diameter);
        int rightdepth = maxDepth(root->right,diameter);
        diameter = max(leftdepth+rightdepth , diameter);
        return 1+ max(leftdepth,rightdepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxDepth(root,diameter);
        return diameter;
    }
};
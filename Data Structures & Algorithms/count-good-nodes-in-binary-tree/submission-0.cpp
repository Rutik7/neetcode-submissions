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
    void helper(TreeNode* root,vector<int>& goodNode,int currpathmaximum)
    {
        //base conditiion
        if(root == nullptr) return;

        //good node finding logic
        if(root->val >= currpathmaximum)
        {
            goodNode.push_back(root->val);
        }
        currpathmaximum = max(currpathmaximum, root->val);

        //recurssion logic
        helper(root->left,goodNode,currpathmaximum);
        helper(root->right,goodNode,currpathmaximum);
    }
    int goodNodes(TreeNode* root) {

        if(root == nullptr) return 0;
        vector<int> goodNode;
        //root node is always good node
        goodNode.push_back(root->val);
        
        if(root->left)
        {
            helper(root->left,goodNode,root->val);
        }
        if(root->right)
        {
            helper(root->right,goodNode,root->val);
        }

        return goodNode.size();

    }
};
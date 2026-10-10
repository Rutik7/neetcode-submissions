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
    void helper(TreeNode* root,int& goodNode,int currpathmaximum)
    {
        //base conditiion
        if(root == nullptr) return;

        //good node finding logic
        if(root->val >= currpathmaximum)
        {
            goodNode++;
        }
        currpathmaximum = max(currpathmaximum, root->val);

        //recurssion logic
        helper(root->left,goodNode,currpathmaximum);
        helper(root->right,goodNode,currpathmaximum);
    }
    int goodNodes(TreeNode* root) {

        if(root == nullptr) return 0;
        int goodNode = 0;
        
        helper(root,goodNode,root->val);

        return goodNode;

    }
};
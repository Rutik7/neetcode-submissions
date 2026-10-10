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
    bool helper(TreeNode* root, long long maxval, long long minval)
    {
        // base condition  
        if(root == nullptr) return true;

        // validation logic return false if failes
        //minval < root->val < maxval
        if(root->val <= minval || root->val >= maxval)
        {
            return false;
        } 

        //recurssion logic

        // going left means every node in the left subtree's value is strickely less than the root val 
        // so maxval  = root->val

        bool validleft = helper(root->left,root->val,minval);
        // going right means every nodo in the right subtree is strickely greater than the root->val
        // so minval  = root->val
        bool validright = helper(root->right,maxval,root->val);

        return validleft && validright;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LLONG_MAX,LLONG_MIN);
    }
};
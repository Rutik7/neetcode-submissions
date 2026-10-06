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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //since a node can be a desendant of itself
        if(p == root || q == root) return root;

        TreeNode* lca;
        //what are the possibilities to finding the p and q

        if(p && q)
        {
            // 1. both p and q are in left subtree
            if(p->val < root-> val && q->val < root->val)
            {
                lca = lowestCommonAncestor(root->left,p,q);
            }

            //2. both p and q are in right subtree
            else if(p->val > root->val && q->val > root->val)
            {
                lca = lowestCommonAncestor(root->right,p,q);
            }

            //3. root become spilt point 
            // p is left sub tree and q is in right subtree
            // or vise versa q is in left and p is in right

            else if((p->val < root->val && q->val > root->val) ||
            p->val > root->val && q->val < root->val)
            {
                return root;
            }
        }

        return lca;

    }
};

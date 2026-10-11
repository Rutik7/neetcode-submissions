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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int prestart, int preend, int instart, int inend , unordered_map<int,int> &inorderhash)
    {
        //my base condition 
        // since the both arrays shrink simultaneously , I can check either pair of indices (or both)
        if(prestart > preend || instart > inend)
        {
            return nullptr;
        }

        // now I need to create a new TreeNode
        TreeNode* root = new TreeNode(preorder[prestart]);

        // calculate the leftsize and rightsize

        int inroot = inorderhash[root->val];

        int nodeleft = inroot - instart;


        // now recurssion call for root->left
        root->left = build(preorder,inorder,prestart+1,prestart+nodeleft,instart,inroot-1,inorderhash);

        // recurssion call for root->right
        root->right = build(preorder,inorder,prestart + nodeleft + 1,preend,inroot+1,inend,inorderhash);

        // return the root;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderHash;
        int n = inorder.size();
        for(int i = 0;i<n;i++)
        {
            inorderHash[inorder[i]] = i;
        }


        return build(preorder,inorder,0,n-1,0,n-1,inorderHash);
    }
};
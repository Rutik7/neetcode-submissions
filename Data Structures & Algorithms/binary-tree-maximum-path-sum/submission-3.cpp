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
    int ans = INT_MIN;
public:
    

    int traverse(TreeNode* root)
    {
        if(root == nullptr) return 0;

        // calculate left down and rightdown 
        int leftdown = traverse(root->left);
        int rightdown = traverse(root->right);

        //include current node in a path 
        int currentpath = root->val + leftdown + rightdown;
        ans = max(ans,root->val+leftdown+rightdown);

        return max(0,root->val + max(leftdown,rightdown));
        
    }

    int maxPathSum(TreeNode* root) {
        traverse(root);
        return ans;
    }
};
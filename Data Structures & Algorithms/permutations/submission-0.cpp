class Solution {
public:
    void helper(vector<int>& nums,int index,vector<vector<int>>& result,vector<int>& curr_permutation,vector<bool>& used)
    {
        if(curr_permutation.size() == nums.size())
        {
            result.push_back(curr_permutation);
            return;
        }

        for(int i = 0;i<nums.size();i++)
        {
            //pick the current number
            if(used[i]) continue;
            used[i] = true;
            curr_permutation.push_back(nums[i]);
            helper(nums,i+1,result,curr_permutation,used);
            curr_permutation.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> result;
        vector<bool> used(nums.size(),false);
        helper(nums,0,result,curr,used);
        return result;
    }
};
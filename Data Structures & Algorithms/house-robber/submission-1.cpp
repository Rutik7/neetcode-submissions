class Solution {
public:

    // Recurssion and Memonization approach 
    
    int helper(vector<int>& nums, int index,vector<int>& dp)
    {
        if(index >= nums.size())
        {
            return 0;
        }
        
        if(dp[index]!= -1)
        {
            return dp[index];
        }

        // rob the house
        int robbed = nums[index]+ helper(nums,index+2,dp);

        // skip the house
        int skipped = helper(nums,index+1,dp);

        return dp[index] = max(robbed,skipped);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};
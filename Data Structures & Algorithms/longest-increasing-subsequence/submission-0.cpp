class Solution {
public:
    int helper(vector<int>& nums, int index,vector<int>& dp)
    {
        if(index >= nums.size())
        {
            return 0;
        }

        if(dp[index] != -1)
        {
            return dp[index];
        }

        int maxlen = 1;
        for(int i = index+1 ; i<nums.size();i++)
        {
            if(nums[index]<nums[i])
            {
                // then it's strictly increasing 
                maxlen = max(maxlen, 1 + helper(nums,i,dp));
                
            }
        }
        return dp[index] = maxlen;
    }

    int lengthOfLIS(vector<int>& nums) {
        int overallMax = 0;
        vector<int> dp (nums.size(),-1);
        for(int i = 0;i<nums.size();i++)
        {
            overallMax = max(overallMax,helper(nums,i,dp));
        }
        return overallMax;

    }
};
class Solution {
public:
    int helper(vector<int>& nums,int start,int end)
    {
        int n = nums.size();
        vector<int> dp(n+2,0);

        for(int i = end - 1;i>=start;i--)
        {
            int robbed = nums[i] + dp[i+2];
            int skipped = dp[i+1];

            dp[i] = max(robbed,skipped);

        }
        return dp[start];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(helper(nums,0,n-1),helper(nums,1,n));
    }
};
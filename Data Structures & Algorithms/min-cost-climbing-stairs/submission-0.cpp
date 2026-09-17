class Solution {
public:
    int helper(vector<int>& cost,int index,vector<int>& dp)
    {
        if(index >= cost.size())
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }

        return dp[index] = cost[index] + min( helper(cost,index+1,dp) , helper(cost,index+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);

        return min(helper(cost,0,dp) , helper(cost,1,dp));
    }
};
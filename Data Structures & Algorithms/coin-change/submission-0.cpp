class Solution {
public:
    int count = 0;
    int helper(vector<int>& coins,int amount, vector<int>& dp)
    {
        if(amount == 0)
        {
            return 0;
        }
        if(amount < 0)
        {
            return 1e9;
        }
        if(dp[amount]!= -1) return dp[amount];
        // how do I pick the coins
        
        
        int ans = 1e9; // why not INT_MAX coz, when it return INT_MAX + 1 it go overflow
        for(int i = 0; i < coins.size(); i++)
        {
            if(coins[i] <= amount)
            {
                int result = 1 + helper(coins,amount-coins[i],dp);
                ans  = min(ans,result);
            }
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        //sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,-1);
        int ans = helper(coins,amount,dp);
        
        return ans==1e9?-1:ans;
        
    }
};
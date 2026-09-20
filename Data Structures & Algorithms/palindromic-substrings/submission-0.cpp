class Solution {
public:
    int countSubstrings(string s) {
        //brute force 
        // try every substring 
        int res = 0;
        int len = 0;
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i = n-1;i>=0;i--)
        {
            for(int j = i;j<n;j++)
            {
                if(s[i] == s[j])
                {
                    if(j-i <= 1)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if(dp[i][j])
                {
                    res += 1;
                }
            }
        }
        return res;
    }
};

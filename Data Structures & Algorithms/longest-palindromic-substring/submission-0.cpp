class Solution {
public:
    string longestPalindrome(string s) {
        //brute force 
        // try every substring 
        string res;
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

                if(dp[i][j] &&  (j-i+1)>len)
                {
                    res = s.substr(i,j-i+1);
                    len = res.length();
                }
            }
        }
        return res;
    }
};

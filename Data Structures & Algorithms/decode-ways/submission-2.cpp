class Solution {
public:
//bottom up approach / iterative solution
    int numDecodings(string s) {
        int n = s.length();
        if(s[0] == '0') return 0;

        vector<int> dp (n+1 , 0);
        dp[n] = 1;

        for(int i = n - 1; i>=0;i--)
        {
            if(s[i] == '0') continue;

            // Take one digit
            dp[i] = dp[i+1];

            // Take two digit
            if(i+1 < n)
            {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                if(num >= 10 && num <= 26)
                {
                    dp[i] += dp[i+2];
                }
            }
        }

        return dp[0];
    }
};
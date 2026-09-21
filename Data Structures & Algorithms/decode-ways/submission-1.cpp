class Solution {
public:
    int helper(string s, int index, vector<int>& dp)
    {
        if(index >= s.length())
        {
            return 1; // found one way
        } 
        // here I have some questions
        // how I check that it's not leading 0 
        if(s[index] == '0') return 0;

        if(dp[index]!= 0) return dp[index];

        // now I need to check the two-digit number 
        int ways = 0;
        if(index+1 < s.length())
        {
            int num = (s[index] - '0') * 10 + (s[index + 1] - '0');
            
            if(num >= 10 && num <= 26) 
            {
                ways = helper(s,index+2,dp);
                dp[index+2] = ways;
            }
        }
        


        return dp[index] = helper(s,index+1,dp) + ways;

    }

    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n+1,0);
        return helper(s,0,dp);

    }
};

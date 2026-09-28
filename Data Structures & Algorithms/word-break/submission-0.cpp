class Solution {
public:

    bool isPresentinDict(const string& word, const unordered_set<string>& dictset)
    {
        return dictset.find(word) != dictset.end();
    }

    bool helper(string &s,unordered_set<string>& dictset,int index,vector<int>& dp)
    {
        if(index >= s.length())
        {
            return true;
        }
        if(dp[index] != -1)
        {
            return dp[index] == 1;
        }
        bool ans = false;
        for(int i = index;i<s.length();i++)
        {
            string curr = s.substr(index,i - index + 1);
            if(isPresentinDict(curr, dictset))
            {
                //true;
                // then move my index?
                if(helper(s,dictset,i + 1,dp))
                {
                    dp[index] = 1;
                    return true;
                }
            }
            
        }
        dp[index] = 0;
        return false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictset ({wordDict.begin(),wordDict.end()});
        vector<int> dp (s.length() , -1);
        return helper(s,dictset,0,dp);
    }
};
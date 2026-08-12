class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0 || n == 1) return n;

        unordered_set<char> uset;
        int ans = 0;
        int left = 0;

        for(int right = 0; right<n; right++)
        {
            // if character is present then remove from set from left 
            while(uset.find(s[right]) != uset.end())
            {
                uset.erase(s[left]);
                left++;
            }
            
            // add current character to set
            uset.insert(s[right]);

            // update the ans
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
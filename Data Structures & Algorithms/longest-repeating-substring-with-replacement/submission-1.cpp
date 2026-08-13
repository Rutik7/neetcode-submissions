class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int maxFreq = 0;
        int left = 0;
        int n = s.length();
        unordered_map<char,int> freq;

        for(int right = 0; right < n;right++)
        {
            // add current charater
            freq[s[right]]++;

            // find the highest frequency in current window
            maxFreq = max(maxFreq,freq[s[right]]);

            // how many replacemant needed
            int replacement = (right - left + 1) - maxFreq;

            while(replacement > k)
            {
                // invalid window
                freq[s[left]]--;
                left++;

                replacement = (right - left + 1) - maxFreq;
            }

            // valid window
            ans = max(ans,right - left + 1);
        }

        return ans;
    }
};
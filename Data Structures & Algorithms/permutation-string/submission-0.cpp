class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        if (k > s2.length()) return false;
        unordered_map<char,int> freq , tempfreq;
        
        //maintain the fixed size window of k in s2

        // store the freq of characters in s1
        for(char ch : s1)
        {
            freq[ch]++;
        }

        int left = 0;
        int n = s2.length();

        // need to maintain the k size window
        for(int i = 0;i<k ;i++)
        {
            tempfreq[s2[i]]++;
        }
        if(freq == tempfreq) return true;

        for(int right = k; right<n;right++)
        {
            // now slide the window 
            // remove the left element from window
            tempfreq[s2[left]]--;
            if(tempfreq[s2[left]] == 0)
            {
                tempfreq.erase(s2[left]);
            }
            left++;
            // add the right element to the window
            tempfreq[s2[right]]++;

            if(freq == tempfreq) return true;
        }

        return false;
    }
};
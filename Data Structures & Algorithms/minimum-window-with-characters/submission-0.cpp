class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        
        unordered_map<char,int> tfreq,windowfreq;

        // store the frequency of each character required by t
        for(char ch: t)
        {
            tfreq[ch]++;
        }

        int left = 0;
        int have = 0; // number of required characters currently satisfied
        int need = t.length(); // total number of charaters required from t
        
        // our ans 
        int start = 0; 
        int minlen = INT_MAX;

        for(int right = 0 ; right < s.length() ; right++)
        {
            char ch = s[right];
            windowfreq[ch]++;

            // this occureence satisfies a requirement
            if(tfreq.find(ch) != tfreq.end() && 
                windowfreq[ch] <= tfreq[ch] ) 
            {
                have++;
            }

            while (have == need)
            {
                // that means our string t is now substring of s's current window
                //update the start

                if(right - left + 1 < minlen)
                {
                    minlen = right-left+1;
                    start = left;
                }

                // now remove the left char
                char leftchar = s[left];
                windowfreq[leftchar]--;

                if(tfreq.find(leftchar) != tfreq.end() && 
                    windowfreq[leftchar] < tfreq[leftchar])
                    {
                        have--;
                    }
                
                left++;
            }
        }

        if(minlen == INT_MAX) return "";

        return s.substr(start,minlen);



    }
};
class Solution {
public:
    bool isPalindrome(const string& s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
            return false;

            start++;
            end--;
        }
        return true;
    }

    void helper(const string& s, int start, vector<vector<string>>& result, vector<string>& curr_palindrome)
    {
        // base condition 
        if(start >= s.length())
        {
            result.push_back(curr_palindrome);
            return;
        } 

        // now each index I have to take decision Where should I end my next substring?

        for(int i=start; i<s.length();i++)
        {
            //check my current partion is palindrome or not
            if(isPalindrome(s,start,i))
            {
                //insert into a curr_palindrome
                curr_palindrome.push_back(s.substr(start,i-start+1));

                //now try to find next substring
                helper(s,i+1,result,curr_palindrome);
                
                // backtrack

                curr_palindrome.pop_back();
            }
        }
        




    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr_palindrome;
        helper(s,0,result,curr_palindrome);
        return result;
    }
};
class Solution {
public:
    void helper(const string& digits, int index,
                unordered_map<char, string>& umap, string& currComb, vector<string>& result) 
    {
        if (currComb.length() == digits.length()) 
        {
            result.push_back(currComb);
            return;
        }

        for(char ch : umap[digits[index]])
        {
            // choose ch
            currComb.push_back(ch);
            // recurse call with index+1
            helper(digits,index+1,umap,currComb,result);
            //backtrack
            currComb.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> result;
        string currcomb;
        if(digits.length() != 0)
            helper(digits,0,mp,currcomb,result);
        return result;
    }
};
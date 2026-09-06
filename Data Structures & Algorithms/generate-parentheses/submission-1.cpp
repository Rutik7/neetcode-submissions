
class Solution {
public:
    void helper(int n, string& curr_valid, vector<string>& result,
                int open, int close)
    {
        // Base case:
        // I have used exactly 2*n parentheses
        if((open + close) == 2 * n)
        {
            result.push_back(curr_valid);
            return;
        }

        // Choice 1: Add an opening '('
        // I can add '(' only if we haven't used n opening brackets yet
        if(open < n)
        {
            curr_valid.push_back('(');

            // Make recursive call after adding '('
            helper(n, curr_valid, result, open + 1, close);

            // Backtrack: remove the '(' I just added
            curr_valid.pop_back();
        }

        // Choice 2: Add a closing ')'
        // I can add ')' only when there is an unmatched '('
        if (close < open)
        {
            curr_valid.push_back(')');

            // Make recursive call after adding ')'
            helper(n, curr_valid, result, open, close + 1);

            // Backtrack: remove the ')' I just added
            curr_valid.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current;

        // Initially, I have used 0 opening and 0 closing brackets
        helper(n, current, result, 0, 0);

        return result;
    }
};


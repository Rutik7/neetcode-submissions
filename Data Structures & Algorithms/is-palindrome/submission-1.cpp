class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while(start < end)
        {
            // skip the non-alphanumeric from left
            while(start<end && !isalnum(s[start]))
            {
                start++;
            }

            //skip the non-alphanumeric from right
            while(start<end && !isalnum(s[end]))
            {
                end--;
            }

            // check start and end charecter 

            if(tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};

class Solution {
   public:
    bool isValid(string s) {
        bool changed = true;
        int n = s.size(); // here this won't work because we remove the pair
        // so size will change

        while (changed) {
            changed = false;

            for (int i = 0; i < s.size(); i++) {
                if ((s[i] == '(' && s[i + 1] == ')') || (s[i] == '{' && s[i + 1] == '}') ||
                    (s[i] == '[' && s[i + 1] == ']')) 
                {
                    s.erase(i,2); //Remove the pair
                    changed = true;
                    break;  // start scanning
                }
            }
        }

        return s.empty();
    }
};

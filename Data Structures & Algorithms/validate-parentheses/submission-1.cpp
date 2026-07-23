class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) 
        {
            // if opning brackets
            if (ch == '(' || ch == '{' || ch == '[') 
            {
                st.push(ch);
            }

            // if closing brackets
            else if (ch == ')' || ch == '}' || ch == ']') 
            {
                if (st.empty())
                    return false;

                char top = st.top();

                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) 
                {
                    st.pop(); // Valid match, pop the stack
                }

                else
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
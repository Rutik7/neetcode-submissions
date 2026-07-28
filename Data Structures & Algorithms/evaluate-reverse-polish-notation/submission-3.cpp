class Solution {
public:
    bool isOperator(const string &token)
    {
        return token == "+" ||
            token == "-" ||
            token == "/" ||
            token == "*" ;
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        
        // if it is number then push it into stack

        for (string token : tokens)
        {
            // what if we have token "100" did I have any 
            //string function that return number from string
            

            // how to check the operator 
            if(isOperator(token))
            {
                if(st.size()>=2)
                {
                    int a = st.top();
                    st.pop();

                    int b = st.top();
                    st.pop();

                    if (token == "+")
                    {
                        st.push(b + a);
                    }
                    else if (token == "-")
                    {
                        st.push(b - a);
                    }
                    else if (token == "*")
                    {
                        st.push(b * a);
                    }
                    else
                    {
                        st.push(b / a);
                    }
                }
            }
            else
            {
                st.push(stoi(token));
            }

        }

        return st.top();
    }
};

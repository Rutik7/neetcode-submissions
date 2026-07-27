class MinStack {
    stack<int> minst;
    stack<int> st;

   public:
    MinStack() {}

    void push(int value) 
    { 
        st.push(value);
        if(minst.empty())
        {
            minst.push(value);
        }
        else
        {
            minst.push(min(value,minst.top()));
        }
    }

    void pop() {
        if (!st.empty()) 
            st.pop();

        if(!minst.empty())
            minst.pop();
    }

    int top() 
    { 
        return st.top(); 
    }

    int getMin() 
    {
        return minst.top();
    }
};

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for (char ch : s) 
        {
            if (ch == 'a' or ch == 'b') 
            {
                st.push(ch);
            } 
            else 
            {
                if (!st.empty()) 
                {
                    if (st.top() == 'b') 
                    {
                        st.pop();
                    } 
                    else 
                    {
                        return false;
                    }
                    if (!st.empty() and st.top() == 'a') 
                    {
                        st.pop();
                    } 
                    else 
                    {
                        return false;
                    }
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
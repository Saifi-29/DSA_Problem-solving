class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')' || s[0]=='}' || s[0] == ']')
        return false;
        stack<char> st;
        int i=0;
        while(i<s.size())
        {
            if(s[i] == '(' || s[i]=='{' || s[i] == '[')
            st.push(s[i]);
            else if(!st.empty() && st.top() == '(' && s[i] == ')')
            st.pop();
            else if(!st.empty() && st.top() == '[' && s[i] == ']')
            st.pop();
            else if(!st.empty() && st.top() == '{' && s[i] == '}')
            st.pop();
            else return false;
            i++;
        }
        return st.empty();
        
    }
};
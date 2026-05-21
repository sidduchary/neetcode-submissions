class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char& ch: s) {
            if(ch==']' || ch=='}' || ch==')') {
                if(st.empty() || (ch == ']' && '[' != st.top())) 
                    return 0;
                if(st.empty() || (ch == '}' && '{' != st.top())) 
                    return 0;
                if(st.empty() || (ch == ')' && '(' != st.top())) 
                    return 0;
                st.pop();
            }
            else st.push(ch);
        }
        return st.empty();
    }
};

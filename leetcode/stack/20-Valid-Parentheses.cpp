class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                    return false;
                } else
                    st.push(s[i]);
            }
            else{
            char it = st.top();
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if ((it == '(' && s[i] == ')') || (it == '[' && s[i] == ']') ||
                    it == '{' && s[i] == '}') {
                    st.pop();
                } else
                    return false;
            }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};
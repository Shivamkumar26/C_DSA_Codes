class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            switch (s[i]) {
                case ')' : {
                    if(st.size() && st.top() == '(') st.pop();
                    else return false;
                    break;
                }
                case ']' : {
                    if(st.size() && st.top() == '[') st.pop();
                    else return false;
                    break;
                }
                case '}' : {
                    if(st.size() && st.top() == '{') st.pop();
                    else return false;
                    break;
                }
                default : st.push(s[i]);
            }
        }
        return st.empty();
    }
};
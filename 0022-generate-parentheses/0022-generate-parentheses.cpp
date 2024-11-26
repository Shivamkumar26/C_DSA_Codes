class Solution {
    void solve(int o, int c, string s, vector<string>& res) {
        if(o == 0 && c == 0) res.push_back(s);
        if(o > c || c < 0 || o < 0) return;

        solve(o-1, c, s+'(', res);
        solve(o, c-1, s+')', res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(n, n, "", ans);

        return ans;
    }
};
/*

(
((                                  ()
(((         (()                     ()(   
((()        (()(        (())        ()((        ()()   
((())       (()()       (())(       ()(()       ()()(
((()))      (()())      (())()      ()(())      ()()() 

*/
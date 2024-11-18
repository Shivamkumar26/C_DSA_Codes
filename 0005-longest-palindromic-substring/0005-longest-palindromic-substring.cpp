class Solution {
    void solve(string s, int l, int r, string& res) {
        if(l < 0 || l >= s.size() || r < 0 || r >= s.size() || s[l]!=s[r]) 
        return;

        if(r-l+1 > res.size()) {
            res = s.substr(l, r-l+1);
        }
        solve(s, l-1, r+1, res);
    }
public:
    string longestPalindrome(string s) {
        int n = s.length(), len = 0;
        string res = "";

        for(int i=0; i<n; i++) {
            solve(s, i, i, res);
            solve(s, i, i+1, res);
        }
        return res;
    }
};
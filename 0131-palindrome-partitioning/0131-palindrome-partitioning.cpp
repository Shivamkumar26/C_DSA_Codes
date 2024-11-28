class Solution {
bool isPal(string s) {
    int r = s.size()-1, l = 0;
    while(l < r) {
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
void solve(int i, int n, string& s, vector<string> str, vector<vector<string>>& res) {
    if(i == n) {
        res.push_back(str);
        return;
    }
    for(int j = i; j < n; j++) {
        string tmp = s.substr(i, j+1-i); // a aa aa
        if(isPal(tmp)) {
            str.push_back(tmp);
            solve(j+1, n, s, str, res);
            str.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;

        vector<string> str;

        solve(0, n, s, str, res);
        return res;
    }
};
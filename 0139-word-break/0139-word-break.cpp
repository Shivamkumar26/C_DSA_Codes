class Solution {
    bool solve(int i, int n, string &s, unordered_map<string, int>& mp, vector<int>& dp) {
        if(i == n) return true;   

        if(dp[i] != -1) return dp[i];

        string temp = "";
        for(int j = i; j < n; j++) {
            temp += s[j];
            if(mp.find(temp) != mp.end()) {
                if(solve(j+1, n, s, mp, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wd) {
        int n = s.size();
        int m = wd.size();
        unordered_map<string, int> mp;
        
        vector<int> dp(n+1, -1);
        for(int i=0; i<m; i++) 
            mp[wd[i]]++;

        return solve(0, n, s, mp, dp);
    }
};
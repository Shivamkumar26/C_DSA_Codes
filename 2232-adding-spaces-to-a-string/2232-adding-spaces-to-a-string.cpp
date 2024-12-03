class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();

        sort(spaces.begin(), spaces.end());
        string res;
        int idx = 0;
        for(int i=0; i<n; i++) {
            while(idx != spaces[i]) {
                res += s[idx];
                idx++;
            }
            res += ' ';
            // idx--;
        }
        while(idx < s.size())
        res += s[idx++];

        return res;
    }
};
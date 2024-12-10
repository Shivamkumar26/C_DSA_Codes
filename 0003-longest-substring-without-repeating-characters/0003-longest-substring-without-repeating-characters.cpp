class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        int l = 0, res = 0, len = 0, r = 0;
        while(r < n) {
            if(mp.find(s[r]) != mp.end()) {
                while(mp.find(s[r]) != mp.end()) {
                    mp.erase(s[l]);
                    l++;
                }
                // l++;
            }
            res = max(res, r - l + 1);
            cout << "res " << res << " l " << l << " r " << r << endl;
            mp[s[r]] = r;
            r++;
        }
        return res;
    }
};

/*

t m m z u x t
0 1 2 3 4 5 6

res 1 l 0 r 1
res 2 l 0 r 2
res 2 l 2 r 3
res 2 l 2 r 4
res 3 l 2 r 5
res 4 l 2 r 6
res 4 l 7 r 7


*/
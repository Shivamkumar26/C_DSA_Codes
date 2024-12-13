class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        int l = 0, r = 0, ans = 0;
        while(r < n) {
            mp[s[r]]++;

            if(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                ans += n - r;

                bool flag = false;
                while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                    mp[s[l]]--;
                    l++;
                    ans += (n-r);
                    flag = true;
                }
                if(flag) ans -= (n-r);

            }
            r++;
        }

        return ans;
    }
};
/*

as soon as we get abc res = end - curridx + 1

4 + 3 + 2

a b c a b c
    l   r

ans - 1



acbbcac
5 + 2 + 2 + 2 + 2 - 2 

5 + 2 + 1 + 1 + 1 - 1


exp - 11

*/
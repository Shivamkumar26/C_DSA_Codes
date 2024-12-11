class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int res = 0;

        for(char c = 'A'; c <= 'Z'; c++) {
            int l = 0, i = 0, kk = k;
            while(i < n) {
                if(s[i] != c) {
                    kk--;
                    if(kk == -1) {
                        while(s[l] == c) {
                            l++;
                        }
                        l++;
                        kk++;
                    }
                }
                res = max(res, i-l+1);
                i++;
            }
        }

        return res;
    }
};
/*

    ABABBBBB


*/
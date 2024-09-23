int max(int a, int b) {
    return a >= b ? a: b;
}
int lengthOfLongestSubstring(char* s) {
    
    int *freq = (int *)malloc(sizeof(int)*256);
    memset(freq, 0, 256*sizeof(int));
    
    int n = strlen(s);
    int res = 0, l = 0, r = 0;
    
    while(r < n) {
        // ele not in freq array
        if(freq[s[r]] == 0) {
            res = max(res, r-l+1);
            freq[s[r]] = 1;
        }
        else {
            while(l < r && s[l] != s[r]) {
                freq[s[l]]--;
                l++;
            }
            freq[s[l]]--;
            l++;
            r--;
        }
        r++;
    }
    return res;
}
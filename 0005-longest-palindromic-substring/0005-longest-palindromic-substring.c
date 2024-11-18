void solve(char* s, int l, int r, int n, char* res) {
    if(l < 0 || l >= n || r < 0 || r >= n || s[l] != s[r]) 
    return;

    if(r-l+1 > strlen(res)) {
        int it = 0;
        for(int i=l; i<=r; i++) {
            res[it++] = s[i];
        }
        res[it] = '\0';
    }
    solve(s, l-1, r+1, n, res);
}
char* longestPalindrome(char* s) {
    int n = strlen(s);
    char* res = (char *)malloc(n+1);
    res[0] = '\0';

    for(int i=0; i<n; i++) {
        solve(s, i, i, n, res);
        solve(s, i, i+1, n, res);
    }
    return res;
}
/*

babad



*/
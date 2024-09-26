char* countAndSay(int n) {
    if(n == 1) return "1";

    char* st = countAndSay(n-1);
    
    int sz = strlen(st);
    char* ans = (char *)malloc(sizeof(char)*10000);
    int idx = 0, freq = 1;
    char ch = st[0];

    for(int i = 1; i < sz; i++) {
        char ch2 = st[i];
        if(ch == ch2) {
            freq++;
        }
        else {
            ans[idx++] = freq + '0';
            ans[idx++] = ch;

            ch = ch2;
            freq = 1;
        }
    }
    ans[idx++] = freq + '0';
    ans[idx++] = ch;
    ans[idx] = '\0';
    return ans;
}
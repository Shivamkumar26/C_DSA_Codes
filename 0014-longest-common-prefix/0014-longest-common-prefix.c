char* longestCommonPrefix(char** strs, int n) {
    char* ans = (char*)malloc(200);
    ans[0] = '\0';

    for(int i = 0; i < strlen(strs[0]); i++) {
        char ch = strs[0][i];
        for(int j = 0; j < n; j++) {
            if(ch != strs[j][i]) {
                ans[i] = '\0';
                return ans;
            }
        }
        ans[i] = ch;
    }
    ans[strlen(strs[0])] = '\0';
    return ans;
}
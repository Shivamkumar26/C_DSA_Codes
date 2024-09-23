bool isPal(char* s) {
    int n = strlen(s);
    int l = 0, r = n-1;

    while(l < r) {
        if(s[l++]!=s[r++]) return false;
    }
    return true;
}

char* conversion(int n, int base) {
    char *str = (char *)malloc(32);  
    int idx = 0;
    
    while (n > 0) {
        str[idx++] = n % base + '0';  
        n /= base;
    }
    
    str[idx] = '\0';
    int start = 0, end = idx - 1;

    while (start < end) { //reverse
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
    
    return str;
}

bool isStrictlyPalindromic(int n) {
    for(int i = 2; i <= n; i++) {
        char* str = conversion(n, i);
        if(!isPal(str)) return false;
    }
    return true;
}
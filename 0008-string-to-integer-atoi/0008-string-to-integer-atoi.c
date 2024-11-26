int myAtoi(char* s) {
    long long res = 0;
    int n = strlen(s), i = 0;
    bool isneg = false;
    while(i < n) {
        while(i < n && s[i] == ' ') i++;
        if(s[i] == '-' || s[i] == '+') {
            isneg = (s[i] == '-' ? true : false);
            i++;
        }
        while(i < n && s[i] <= '9' && s[i] >= '0') {
            res = res*10 + (s[i] - '0');
            if(isneg) {
                if((-res-1) < INT_MIN) return INT_MIN;
            } 
            else if(res > INT_MAX) return INT_MAX; 
            i++;
        }
        break;
        i++;
    }
    return (isneg) ? -res : res;
}
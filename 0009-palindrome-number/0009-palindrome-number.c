bool isPalindrome(int x) {
    if(x < 0) return false;
    long rev = x, ans = 0;
    
    while(x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return rev == ans;
}
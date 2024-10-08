int reverse(int x){
    long res = x;
    bool isNeg = (x < 0);
    
    if(isNeg) res *= (-1);
    long ans = 0;
    
    while(res) {
        int rem = res % 10;
        ans = ans*10 + rem;
        res /= 10;
        
        if(ans < INT_MIN || ans > INT_MAX) return 0;
    }
    
    if(isNeg) return -1*ans;
    return ans;
}
int max(int a, int b) {
    return a >= b ? a : b;
}
int min(int a, int b) {
    return a <= b ? a : b;
}

int maxArea(int* height, int n) {
    int res = 0;
    int lmax = 0, rmax = 0;
    int l = 0, r = n-1;
    
    while(l < r) {
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);
        
        int mul = min(lmax, rmax);
        res = max(res, mul*(r-l));
        
        if(lmax < rmax) l++;
        else r--;
    }
    return res;
}
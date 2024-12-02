class Solution {
    int mod = 1e9+7;
public:
    double myPow(double x, int n) {
        if(n==0) return (double)1;

        long long nn = n;
        bool neg = false;
        if(nn < 0) neg = true;
        if(neg) nn *= -1;

        double ans = 1.0;
        while(nn) {
            if(nn % 2 == 0) {
                x = (double)(x * x);
                nn /= 2;
            }
            else {
                ans = (double)(x * ans);
                nn--;
            }
        }
        if(neg) return 1.0/ans;
        return ans;
    }
};
class Solution {
    int mod = 1e9+7;
    long long pow(long long x, long long n) {
        if(n==0) return 1;

        if(n % 2 == 0) {
            long long t = pow(x, n/2) % mod;
            return ((t % mod) * (t % mod)) % mod;
        }
        return ((x % mod) * (pow(x , n-1) % mod)) % mod;
    }
public:
    int countGoodNumbers(long long n) {
        return (n % 2) ? (pow(5, n/2+1) * pow(4, n/2) % mod) : (pow(5, n/2) * pow(4, n/2) % mod);
    }
};
/*

2^4
(2*2)^2

1-5
2-20
3-100
4-400
5-2000
6-8000


*/
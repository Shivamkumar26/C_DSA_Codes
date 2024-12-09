class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        while(start || goal) {
            if(((start) & 1) != ((goal) & 1))
                res++;
            start = start >> 1;
            goal = goal >> 1;
        }
        return res;
    }
};

/*

1010
0111


011
100

*/
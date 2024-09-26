int min(int a, int b) {
    return a <= b ? a : b;
}

int minSubArrayLen(int target, int* nums, int numsSize) {
    int sum = 0;
    int l = 0, r = 0;
    int maxLen = numsSize+2;
    while(r < numsSize) {
        sum += nums[r++];
        while(sum >= target) {
            sum -= nums[l++];
            maxLen = min(maxLen, r-l+1);
        }
    }
    return maxLen == numsSize + 2 ? 0 : maxLen ;
}

/*

2 5 6 8


*/
int max(int a, int b) {
    return a >= b ? a : b;
}
int maxSubArray(int* nums, int n) {
    int sum = 0, maxSum = INT_MIN;
    for(int i=0; i<n; i++) {
        sum = max(nums[i], sum + nums[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
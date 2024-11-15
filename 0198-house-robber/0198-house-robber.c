int solve(int* nums, int idx, int n, int* dp) {
    if(idx >= n) return 0;
    if(dp[idx]!=-1) return dp[idx];

    int steal = nums[idx] + solve(nums, idx+2, n, dp);
    int not_steal = solve(nums, idx+1, n, dp);

    return dp[idx] = (steal > not_steal) ? steal : not_steal;
}
int rob(int* nums, int n) {
    int *dp = (int*)malloc((n+1)*sizeof(int));
    memset(dp, -1, (n+1)*sizeof(int));

    int res = solve(nums, 0, n, dp);
    free(dp);
    return res;
}
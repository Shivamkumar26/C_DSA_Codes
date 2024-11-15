int solve(int* nums, int idx, int n, int* dp) {
    if(idx >= n) return 0;
    if(dp[idx]!=-1) return dp[idx];

    int steal = nums[idx] + solve(nums, idx+2, n, dp);
    int not_steal = solve(nums, idx+1, n, dp);

    return dp[idx] = (steal > not_steal) ? steal : not_steal;
}
int rob(int* nums, int n) {
    if(n==1) return nums[0];

    int *dp = (int*)malloc((n)*sizeof(int));
    memset(dp, -1, (n)*sizeof(int));

    int *dp2 = (int*)malloc((n)*sizeof(int));
    memset(dp2, -1, (n)*sizeof(int));

    int *nums1 = (int*)malloc(n*sizeof(int));
    int *nums2 = (int*)malloc(n*sizeof(int));

    for(int i=0; i<n-1; i++) {
        nums1[i] = nums[i];
        nums2[i] = nums[i+1];
    }

    int res = solve(nums1, 0, n-1, dp);
    int res2 = solve(nums2, 0, n-1, dp2);
    free(dp);
    free(dp2);
    return res2 > res ? res2 : res;
}
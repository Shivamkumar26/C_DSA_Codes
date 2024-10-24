int removeDuplicates(int* nums, int n) {
    int k = 1, idx = 0;
    for(int i=1; i<n; i++) {
        if(nums[i]==nums[idx]) continue;
        else {
            nums[k] = nums[i];
            k++;
            idx = i;
        }
    }
    return k;
}
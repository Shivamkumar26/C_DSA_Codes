int removeElement(int* nums, int n, int val) {
    int k = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] == val) continue;
        else {
            nums[k++] = nums[i];
        }
    }
    return k;
}
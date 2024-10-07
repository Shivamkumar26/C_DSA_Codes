void reverse(int* nums, int s, int e) {
    while(s < e) {
        int temp = nums[s];
        nums[s++] = nums[e];
        nums[e--] = temp;
    }
}
void rotate(int* nums, int n, int k) {
    // if(n==1) return;
    k = k % n;
    reverse(nums, 0, n-k-1);
    reverse(nums, n-k, n-1);
    reverse(nums, 0, n-1);
}
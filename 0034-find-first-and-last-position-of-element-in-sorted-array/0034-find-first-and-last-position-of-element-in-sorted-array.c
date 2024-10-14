/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int lower_bound(int* nums, int n, int target) {
    int l = 0, r = n-1;
    int ans = -1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(nums[mid] == target) ans = mid;
        if(nums[mid] >= target) {
            r = mid-1;
        }
        else l = mid+1;
    }

    return ans;
} 

int upper_bound(int* nums, int n, int target) {
    int l = 0, r = n-1;
    int ans = -1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(nums[mid] == target) ans = mid;
        if(nums[mid] > target) {
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    return ans;
} 

int* searchRange(int* nums, int n, int target, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*)malloc(sizeof(int)*2);

    ans[0] = lower_bound(nums, n, target);
    ans[1] = upper_bound(nums, n, target);

    return ans; 
}
int search(int* nums, int n, int target) {
    int l = 0, r = n-1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(nums[mid] == target) return mid;

        //left part sorted
        if(nums[l] <= nums[mid]) {
            if(target >= nums[l] && target <= nums[mid]) {
                r = mid-1;
            }
            else l = mid+1;
        }
        //right part sorted 
        else {
            if(target <= nums[r] && target >= nums[mid]) l = mid+1;
            else r = mid-1;
        }
    }
    return -1;
}
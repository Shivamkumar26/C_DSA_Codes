/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int n, int target, int* returnSize) {
    int* arr = (int *)malloc(sizeof(int)*2);
    *returnSize = 2;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(i != j) {
                if(nums[i] + nums[j] == target) {
                    arr[0] = i;
                    arr[1] = j;
                    return arr;
                }
            }
        }
    }
    arr[0] = -1;
    arr[1] = -1;
    return arr;
}
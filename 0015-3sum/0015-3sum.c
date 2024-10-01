/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int** threeSum(int* nums, int n, int* returnSize, int** returnColumnSizes) {
    qsort(nums, n, sizeof(int), cmp);

    int** res = (int**)malloc(sizeof(int*)*(100000)); 
    *returnSize = 0;

    for(int i=0; i<n-2; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int n1 = nums[i];
        int rem = 0 - n1;
        
        int l = i+1, r = n-1;
        while(l < r) {
            if(nums[l] + nums[r] == rem) {
                res[*returnSize] = (int*)malloc(sizeof(int)*3);
                res[*returnSize][0] = n1;
                res[*returnSize][1] = nums[l];
                res[*returnSize][2] = nums[r];
                (*returnSize)++;

                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--;
                l++;
                r--;
            }
            else if(rem > nums[l] + nums[r]) l++;
            else r--;
        }
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0; i< *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return res;
}
/*

-4 -1 -1 0 1 2 

*/
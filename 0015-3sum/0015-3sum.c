/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(int*)a- *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* n, int** m) {

    qsort(nums, numsSize, sizeof(int), cmp);
    int** res = (int**)malloc(sizeof(int*)*3001*3001);
    *n = 0;

    for(int i = 0; i < numsSize-2; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int l = i + 1, r = numsSize - 1;
        while(l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if(sum == 0) {
                res[*n] = (int*)malloc(sizeof(int)*3);
                res[*n][0] = nums[i];
                res[*n][1] = nums[l];
                res[*n][2] = nums[r];
                (*n)++;

                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--; 
                l++;
                r--;
            }
            else if(sum < 0) l++;
            else r--;
        }
    }
    *m = (int*)malloc(sizeof(int)*(*n));
    for(int i=0; i<*n; i++){
        (*m)[i] = 3;
    }
    return res;
}
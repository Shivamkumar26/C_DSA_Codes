void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void sortColors(int* nums, int n) {
    int r = n-1, i = 0, l = 0;

    while(i <= r) {
        if(nums[i] == 0) {
            swap(&nums[l], &nums[i]);
            l++;
            i++;
        }
        else if(nums[i] == 1) {
            i++;
        }
        else if(nums[i] == 2) {
            swap(&nums[r], &nums[i]);
            r--;
        }

        // for(int i=0; i<n; i++) {
        //     printf("%d ", nums[i]);
        // }
        // printf("\n");
    }
}
/*
2 0 2 1 1 0 1 0 2 
2 0 2 1 1 0 1 0 2
0 0 0 1 1 1 2 2 2  



2 0 2 1 1 0

0 0 2 1 1 2
0 0 1 1 2 2 
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRepeatedDnaSequences(char* s, int* n) {
    int arr[1048577];
    memset(arr, 0, sizeof(arr));

    char** res = (char**)malloc(sizeof(char*)*(100000));
    int len = strlen(s);

    int resLen = 0;
    for(int i=0; i < len-9; i++) {
        int idx = 0;

        for(int j=0; j<10; j++) {
            if(s[i+j] == 'A') {
                idx += (0 * (int)pow(4, j));
            }
            else if(s[i+j] == 'C') {
                idx += (1 * (int)pow(4, j));
            } 
            else if(s[i+j] == 'G') {
                idx += (2 * (int)pow(4, j));
            }
            else if(s[i+j] == 'T') {
                idx += (3 * (int)pow(4, j));
            }
        }
        arr[idx]++;
        if(arr[idx] == 2) {
            // ans mei add
            res[resLen] = (char*)malloc(sizeof(char) * 11);  
            strncpy(res[resLen], &s[i], 10);
            res[resLen][10] = '\0';

            resLen++;
        }
    }
    *n = resLen;
    return res;
}
/*

0000011111 
0000011111
0000002224
44


4^0 + 4^1 + 4^2 + 4^3 + 4^4 = 341

341 % 4 = 1
341 / 4 = 85

85 % 4 = 1
85 / 4 = 21

21 % 4 = 1
21/4 = 5

5%4 = 1
5/4 = 1

1 % 4 = 1
1/4 = 0



33333333333333

*/
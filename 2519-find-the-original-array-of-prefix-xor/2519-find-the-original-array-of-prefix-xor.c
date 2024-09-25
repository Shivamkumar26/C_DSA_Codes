/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findArray(int* pref, int sz, int* retSize) {
    int *res = (int *)malloc(sizeof(int)*sz);
    *retSize = sz;

    res[0] = pref[0];
    for(int i=1; i<sz; i++) {
        res[i] = pref[i-1] ^ pref[i];
    }
    return res;
}
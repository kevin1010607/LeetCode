/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* t, int tSize, int* returnSize){
    int *res = (int*)malloc(tSize*sizeof(int));
    *returnSize = tSize;
    for(int i = tSize-1; i >= 0; i--){
        int j = i+1;
        while(j<tSize && t[j]<=t[i]) j = res[j]>0?j+res[j]:tSize;
        res[i] = j==tSize?0:j-i;
    }
    return res;
}
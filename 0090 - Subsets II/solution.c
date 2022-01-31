/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {return *(const int*)a-*(const int*)b;}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int n = numsSize, idx = 0;
    int **res = (int**)malloc((1<<n)*sizeof(int*));
    *returnColumnSizes = (int*)malloc((1<<n)*sizeof(int));
    qsort(nums, n, sizeof(int), cmp);
    for(int i = 0; i < (1<<n); i++){
        int t = 0, id = 0, flag = 0;
        for(int j = 0; j < n; j++){
            if(j>0 && nums[j-1]==nums[j] && (i&(3<<(j-1)))==(1<<j)){
                flag = 1; break;
            }
            if(i&(1<<j)) t++;
        }
        if(flag) continue;
        res[idx] = (int*)malloc(t*sizeof(int));
        for(int j = 0; j < n; j++){
            if(i&(1<<j)) res[idx][id++] = nums[j];
        }
        (*returnColumnSizes)[idx++] = id;
    }
    *returnSize = idx;
    res = realloc(res, idx*sizeof(int*));
    *returnColumnSizes = realloc(*returnColumnSizes, idx*sizeof(int));
    return res;
}
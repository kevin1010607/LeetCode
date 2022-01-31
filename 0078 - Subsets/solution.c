/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int n = numsSize, idx = 0;
    int **res = (int**)malloc((1<<n)*sizeof(int*));
    *returnColumnSizes = (int*)malloc((1<<n)*sizeof(int));
    for(int i = 0; i < (1<<n); i++){
        int t = 0, id = 0;
        for(int j = 0; j < n; j++) if(i&(1<<j)) t++;
        res[idx] = (int*)malloc(t*sizeof(int));
        for(int j = 0; j < n; j++) if(i&(1<<j)) res[idx][id++] = nums[j];
        (*returnColumnSizes)[idx++] = id;
    }
    *returnSize = idx;
    return res;
}
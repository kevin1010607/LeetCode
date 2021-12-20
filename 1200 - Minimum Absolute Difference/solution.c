/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {return *(const int*)a-*(const int*)b;}
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    int d = (int)(1e7), idx = 0, cap = 0;
    int **res = (int**)malloc(10000*sizeof(int*));
    *returnColumnSizes = (int*)malloc(10000*sizeof(int));
    qsort(arr, arrSize, sizeof(int), cmp);
    for(int i = 1; i < arrSize; i++){
        int now = arr[i]-arr[i-1];
        if(now <= d){
            if(now < d) d = now, idx = 0;
            if(idx == cap) res[cap++] = (int*)malloc(2*sizeof(int));
            res[idx][0] = arr[i-1], res[idx][1] = arr[i];
            (*returnColumnSizes)[idx] = 2, idx++;
        }
    }
    for(int i = cap-1; i >= idx; i--) free(res[i]);
    *returnSize = idx;
    return res;
}
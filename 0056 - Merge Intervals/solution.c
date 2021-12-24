/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define max(a,b) a>b?a:b
int cmp(const void *a, const void *b){
    return **(const int**)a-**(const int**)b;
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int **res = (int**)malloc(50*sizeof(int*)), idx = 1;
    *returnColumnSizes = (int*)malloc(50*sizeof(int));
    (*returnColumnSizes)[0] = 2;
    res[0] = (int*)malloc(2*sizeof(int));
    res[0][0] = intervals[0][0], res[0][1] = intervals[0][1];
    for(int i = 1; i < intervalsSize; i++){
        if(intervals[i][0] <= res[idx-1][1]) res[idx-1][1] = max(res[idx-1][1], intervals[i][1]);
        else{
            (*returnColumnSizes)[idx] = 2;
            res[idx] = (int*)malloc(2*sizeof(int));
            res[idx][0] = intervals[i][0], res[idx][1] = intervals[i][1];
            idx++;
        }
    }
    *returnSize = idx;
    return res;
}
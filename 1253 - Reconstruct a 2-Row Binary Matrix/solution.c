/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes){
    int n = colsumSize;
    int **res = (int**)malloc(2*sizeof(int*));
    res[0] = (int*)calloc(n, sizeof(int));
    res[1] = (int*)calloc(n, sizeof(int));
    *returnColumnSizes = (int*)malloc(2*sizeof(int));
    (*returnColumnSizes)[0] = (*returnColumnSizes)[1] = n;
    *returnSize = 2;
    for(int i = 0; i < n; i++){
        switch(colsum[i]){
            case 1:
                if(upper > lower) res[0][i] = 1, upper--;
                else res[1][i] = 1, lower--;
                break;
            case 2:
                res[0][i] = res[1][i] = 1, upper--, lower--;
                break;
        }
    }
    if(upper || lower){
        *returnSize = 0;
        free(res[0]), free(res[1]), free(res), free(*returnColumnSizes);
        return NULL;
    }
    return res;
}
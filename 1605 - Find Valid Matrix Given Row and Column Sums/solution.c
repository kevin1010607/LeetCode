/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int min(int a, int b) {return a<b?a:b;}
int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes){
    int m = rowSumSize, n = colSumSize;
    int **res = (int**)malloc(m*sizeof(int*));
    *returnColumnSizes = (int*)malloc(m*sizeof(int));
    *returnSize = m;
    for(int i = 0; i < m; i++){
        res[i] = (int*)malloc(n*sizeof(int));
        (*returnColumnSizes)[i] = n;
        for(int j = 0; j < n; j++){
            res[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= res[i][j];
            colSum[j] -= res[i][j];
        }
    }
    return res;
}
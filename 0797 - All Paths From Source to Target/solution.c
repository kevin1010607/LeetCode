/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define maxn 10000
void dfs(int **graph, int graphSize, int *graphColSize, int ***res, int *resSize, int **resColSize, int id, int *now, int nowSize){
    if(id == graphSize-1){
        (*resColSize)[*resSize] = nowSize;
        (*res)[*resSize] = (int*)malloc(nowSize*sizeof(int));
        for(int i = 0; i < nowSize; i++) (*res)[*resSize][i] = now[i];
        (*resSize)++;
        return;
    }
    for(int i = 0; i < graphColSize[id]; i++){
        now[nowSize] = graph[id][i];
        dfs(graph, graphSize, graphColSize, res, resSize, resColSize, graph[id][i], now, nowSize+1);
    }
}
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColSize){
    int **res = (int**)malloc(maxn*sizeof(int*));
    (*returnColSize) = (int*)malloc(maxn*sizeof(int));
    int *now = (int*)malloc(graphSize*sizeof(int));
    now[0] = 0;
    *returnSize = 0;
    dfs(graph, graphSize, graphColSize, &res, returnSize, returnColSize, 0, now, 1);
    free(now);
    res = (int**)realloc(res, (*returnSize)*sizeof(int*));
    (*returnColSize) = (int*)realloc(*returnColSize, (*returnSize)*sizeof(int));
    return res;
}
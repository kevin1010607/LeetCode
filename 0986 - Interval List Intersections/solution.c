/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
int** intervalIntersection(int** list1, int size1, int* colSize1, int** list2, int size2, int* colSize2, int* resSize, int** resColSize){
    int **res = (int**)malloc(1005*sizeof(int*));
    *resColSize = (int*)malloc(1005*sizeof(int));
    int idx = 0, idx1 = 0, idx2 = 0;
    while(idx1<size1 && idx2<size2){
        int s = max(list1[idx1][0], list2[idx2][0]), e = min(list1[idx1][1], list2[idx2][1]);
        if(s <= e){
            res[idx] = (int*)malloc(2*sizeof(int));
            (*resColSize)[idx] = 2;
            res[idx][0] = s, res[idx][1] = e;
            idx++;
        }
        (list1[idx1][1]<list2[idx2][1])?(idx1++):(idx2++);
    }
    *resSize = idx;
    *resColSize = (int*)realloc(*resColSize, idx*sizeof(int));
    res = (int**)realloc(res, idx*sizeof(int*));
    return res;
}
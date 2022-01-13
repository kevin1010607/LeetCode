int cmp(const void *a, const void *b){
    const int *ia = *(const int**)a;
    const int *ib = *(const int**)b;
    return (ia[1]>ib[1])-(ia[1]<ib[1]);
}
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    qsort(points, pointsSize, sizeof(int*), cmp);
    int res = 1, flag = points[0][1];
    for(int i = 1; i < pointsSize; i++){
        if(flag < points[i][0]) res++, flag = points[i][1];
    }
    return res;
}
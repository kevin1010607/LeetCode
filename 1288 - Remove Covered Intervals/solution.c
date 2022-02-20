int cmp(const void *a, const void *b){
    const int *ia = *(const int**)a, *ib = *(const int**)b;
    return ia[0]>ib[0] || (ia[0]==ib[0]&&ia[1]<ib[1]);
}
int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int res = 0, r = -1;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    for(int i = 0; i < intervalsSize; i++){
        if(intervals[i][1] > r) res++, r = intervals[i][1];
    }
    return res;
}
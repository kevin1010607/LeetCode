/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int len(int x){
    int res = 0;
    while(x) res++, x /= 10;
    return res;
}
int* sequentialDigits(int low, int high, int* returnSize){
    int l = len(low), r = len(high), idx = 0;
    int *res = (int*)malloc(100*sizeof(int));
    for(int i = l; i <= r; i++){
        for(int j = 1; j <= 10-i; j++){
            int num = 0, t = i, now = j;
            while(t--) num = 10*num+now, now++;
            if(num>=low && num<=high) res[idx++] = num;
        }
    }
    *returnSize = idx;
    return res;
}
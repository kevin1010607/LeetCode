#define max(a,b) (((a)>(b))?(a):(b))
int findMaxLength(int* nums, int numsSize){
    int res = 0, sum = 0, n = numsSize, p[200005];
    memset(p, 0xff, (2*n+1)*sizeof(int)); p[n] = 0;
    for(int i = 1; i <= n; i++){
        sum += nums[i-1]?1:-1;
        if(p[n+sum] >= 0) res = max(res, i-p[n+sum]);
        else p[n+sum] = i;
    }
    return res;
}
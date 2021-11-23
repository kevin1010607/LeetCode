#define max(a,b) a>b?a:b
int find(int x, int *p){
    if(p[x] == 0) return x;
    return p[x] = find(p[x], p);
}
void uni(int x, int y, int *p){
    int xp = find(x, p), yp = find(y, p);
    if(xp != yp) p[yp] = xp;
}
int largestComponentSize(int* nums, int numsSize){
    int n = 0, res = 0;
    for(int i = 0; i < numsSize; i++) n = max(n, nums[i]);
    int *p = (int*)calloc(n+1, sizeof(int));
    int *s = (int*)calloc(n+1, sizeof(int));
    for(int i = 0; i < numsSize; i++){
        for(int j = 2; j*j <= i; j++){
            if(i%j == 0) uni(j, i, p), uni(i, i/j, p);
        }
    }
    for(int i = 0; i < numsSize; i++){
        int x = ++s[find(nums[i], p)];
        res = max(res, x);
    }
    free(p), free(s);
    return res;
}
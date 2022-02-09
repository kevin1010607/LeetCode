#define max(a,b) (((a)>(b))?(a):(b))
int cmp(const void *a, const void *b) {return *(const int*)a-*(const int*)b;}
int findPairs(int* nums, int numsSize, int k){
    int res = 0, n = numsSize;
    qsort(nums, n, sizeof(int), cmp);
    for(int i = 0, j = 0; i < n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        j = max(j, i+1);
        while(j<n && nums[j]<nums[i]+k) j++;
        if(j == n) break;
        if(nums[j] == nums[i]+k) res++;
    }
    return res;
}
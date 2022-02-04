int cmp(const void *a, const void *b) {return *(const int*)a-*(const int*)b;}
int threeSumClosest(int* nums, int numsSize, int target){
    int n = numsSize, res = 0, m = INT_MAX;
    qsort(nums, n, sizeof(int), cmp);
    for(int i = 0; i < n-2; i++){
        int l = i+1, r = n-1;
        while(l < r){
            int s = nums[i]+nums[l]+nums[r];
            if(s == target) return s;
            if(abs(s-target) < m) m = abs(s-target), res = s;
            s<target?(l++):(r--);
        }
    }
    return res;
}
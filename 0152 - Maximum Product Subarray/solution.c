int max(int a, int b) {return a>b?a:b;}
int min(int a, int b) {return a<b?a:b;}
int maxProduct(int* nums, int numsSize){
    int res = nums[0], ma = nums[0], mi = nums[0];
    for(int i = 1; i < numsSize; i++){
        int tmp = ma;
        ma = max(tmp*nums[i], max(mi*nums[i], nums[i]));
        mi = min(tmp*nums[i], min(mi*nums[i], nums[i]));
        res = max(res, ma);
    }
    return res;
}
#define max(a,b) a>b?a:b
#define INF -0x3f3f3f3f
int maxSubArray(int* nums, int numsSize){
    int res = INF;
    for(int i = 0, sum = 0; i < numsSize; i++){
        res = max(res, sum+nums[i]);
        sum = max(sum+nums[i], 0);
    }
    return res;
}
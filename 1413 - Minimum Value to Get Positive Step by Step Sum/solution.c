#define min(a,b) a<b?a:b
int minStartValue(int* nums, int numsSize){
    int sum = 0, m = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        m = min(m, sum);
    }
    return -m+1;
}
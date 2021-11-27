#define MAX 0x3f3f3f3f
#define MIN -0x3f3f3f3f
#define max(a,b) a>b?a:b
int maximumProduct(int* nums, int numsSize){
    int max1 = MIN, max2 = MIN, max3 = MIN, min1 = MAX, min2 = MAX;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max1) max3 = max2, max2 = max1, max1 = nums[i];
        else if(nums[i] > max2) max3 = max2, max2 = nums[i];
        else if(nums[i] > max3) max3 = nums[i];
        if(nums[i] < min1) min2 = min1, min1 = nums[i];
        else if(nums[i] < min2) min2 = nums[i];
    }
    return max(max1*max2*max3, max1*min1*min2);
}
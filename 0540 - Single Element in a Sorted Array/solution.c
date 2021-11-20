int singleNonDuplicate(int* nums, int numsSize){
    int l = 0, r = numsSize-2;
    while(l <= r){
        int mid = (l+r)/2;
        if(nums[mid] == nums[mid^1]) l = mid+1;
        else r = mid-1;
    }
    return nums[l];
}
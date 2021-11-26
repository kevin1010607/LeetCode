int searchInsert(int* nums, int numsSize, int target){
    int l = 0, r = numsSize-1, mid;
    while(l <= r){
        mid = (l+r)/2;
        if(target == nums[mid]) return mid;
        if(target < nums[mid]) r = mid-1;
        else l = mid+1;
    }
    return l;
}
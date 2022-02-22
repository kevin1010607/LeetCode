int majorityElement(int* nums, int numsSize){
    int res = 0, n = numsSize;
    for(unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(nums[j]&mask) cnt++;
        }
        if(cnt > n/2) res |= mask;
    }
    return res;
}
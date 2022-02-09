int removeDuplicates(int* nums, int numsSize){
    int id = 0;
    for(int i = 0; i < numsSize; i++){
       if(id<2 || nums[i]!=nums[id-2]) nums[id++] = nums[i];
    }
    return id;
}
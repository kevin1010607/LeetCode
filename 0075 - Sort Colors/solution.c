void swap(int *a, int *b) {int t=*a; *a=*b; *b=t;}
void sortColors(int* nums, int numsSize){
    int l = 0, r = numsSize-1, i = 0;
    while(i <= r){
        if(nums[i] == 0) swap(&nums[l++], &nums[i++]);
        else if(nums[i] == 1) i++;
        else if(nums[i] == 2) swap(&nums[r--], &nums[i]);
    }
}
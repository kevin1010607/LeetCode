/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int *a, int *b){int t=*a; *a=*b; *b=t;}
void quickSort(int *nums, int numsSize){
    if(numsSize <= 1) return;
    int i = 1, j = numsSize-1, p = nums[0];
    while(1){
        while(j>0 && nums[j]>=p) j--;
        while(i<numsSize && nums[i]<=p) i++;
        if(i >= j) break;
        swap(nums+i, nums+j);
    }
    swap(nums, nums+j);
    quickSort(nums, j);
    quickSort(nums+j+1, numsSize-j-1);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    quickSort(nums, numsSize);
    int size = 100;
    int **ret = (int**)malloc(size*sizeof(int*));
    *returnColumnSizes = (int*)malloc(size*sizeof(int));
    *returnSize = 0;
    for(int i = 0; i < numsSize; i++){
        if(i!=0 && nums[i]==nums[i-1]) continue;
        int l = i+1, r = numsSize-1;
        while(l < r){
            int t[] = {nums[i], nums[l], nums[r]}, s = t[0]+t[1]+t[2];
            if(s == 0){
                ret[*returnSize] = (int*)malloc(3*sizeof(int));
                (*returnColumnSizes)[*returnSize] = 3;
                for(int i = 0; i < 3; i++) ret[*returnSize][i] = t[i];
                (*returnSize)++;
                if(*returnSize == size){
                    size *= 2;
                    ret = (int**)realloc(ret, size*sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, size*sizeof(int));
                }
                while(l<r && nums[l]==t[1]) l++;
                while(l<r && nums[r]==t[2]) r--;
            }
            else if(s < 0) l++;
            else if(s > 0) r--;
        }
    }
    return ret;
}
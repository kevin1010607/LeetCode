bool canReach(int* arr, int arrSize, int start){
    if(start<0 || start>=arrSize || arr[start]==-1) return false;
    if(arr[start] == 0) return true;
    int l = start-arr[start], r = start+arr[start];
    arr[start] = -1;
    return canReach(arr, arrSize, l)||canReach(arr, arrSize, r);
}
bool validMountainArray(int* arr, int arrSize){
    int n = arrSize, i = 0, j = n-1;
    while(i+1<n && arr[i]<arr[i+1]) i++;
    while(j-1>=0 && arr[j]<arr[j-1]) j--;
    return (i!=0 && j!=n-1 && i==j);
}
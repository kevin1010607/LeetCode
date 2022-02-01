#define min(a,b) (((a)<(b))?(a):(b))
int getKth(int *nums1, int m, int *nums2, int n, int k){
    if(m > n) return getKth(nums2, n, nums1, m, k);
    if(m == 0) return nums2[k-1];
    if(k == 1) return min(nums1[0], nums2[0]);
    int i = min(m, k/2), j = min(n, k/2);
    if(nums1[i-1] < nums2[j-1]) return getKth(nums1+i, m-i, nums2, n, k-i);
    else return getKth(nums1, m, nums2+j, n-j, k-j);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int m = nums1Size, n = nums2Size, l = (m+n+1)/2, r = (m+n+2)/2;
    return (getKth(nums1, m, nums2, n, l)+getKth(nums1, m, nums2, n, r))/2.0;
}
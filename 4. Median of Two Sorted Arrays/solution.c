int nextNum(int *nums1, int nums1Size, int *nums2, int nums2Size, int *idx1, int *idx2){
    if(*idx1<nums1Size && *idx2<nums2Size) return nums1[*idx1]<nums2[*idx2]?nums1[(*idx1)++]:nums2[(*idx2)++];
    else return *idx1<nums1Size?nums1[(*idx1)++]:nums2[(*idx2)++];
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int mid = (nums1Size+nums2Size-1)/2, odd = (nums1Size+nums2Size)%2, idx1 = 0, idx2 = 0, s1 = 0, s2 = 0;
    while(mid--) nextNum(nums1, nums1Size, nums2, nums2Size, &idx1, &idx2);
    s1 = nextNum(nums1, nums1Size, nums2, nums2Size, &idx1, &idx2);
    if(!odd) s2 = nextNum(nums1, nums1Size, nums2, nums2Size, &idx1, &idx2);
    return (odd?(double)s1:(double)(s1+s2)/2);
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = 2*n1;
        while(l <= r){
            int mid1 = l+(r-l)/2, mid2 = n1+n2-mid1;
            int l1 = mid1==0?INT_MIN:nums1[(mid1-1)/2];
            int l2 = mid2==0?INT_MIN:nums2[(mid2-1)/2];
            int r1 = mid1==2*n1?INT_MAX:nums1[mid1/2];
            int r2 = mid2==2*n2?INT_MAX:nums2[mid2/2];
            if(l2 > r1) l = mid1+1;
            else if(l1 > r2) r = mid1-1;
            else return (max(l1, l2)+min(r1, r2))/2.0;
        }
        return -1;
    }
};
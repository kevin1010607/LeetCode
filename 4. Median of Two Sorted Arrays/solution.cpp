class Solution {
public:
    int nextNum(vector<int>& nums1, vector<int>& nums2, int& idx1, int& idx2){
        if(idx1<nums1.size() && idx2<nums2.size()) return nums1[idx1]<nums2[idx2]?nums1[idx1++]:nums2[idx2++];
        else return idx1<nums1.size()?nums1[idx1++]:nums2[idx2++];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size()+nums2.size()-1)/2, odd = (nums1.size()+nums2.size())%2, idx1 = 0, idx2 = 0, s1 = 0, s2 = 0;
        while(mid--) nextNum(nums1, nums2, idx1, idx2);
        s1 = nextNum(nums1, nums2, idx1, idx2);
        if(!odd) s2 = nextNum(nums1, nums2, idx1, idx2);
        return odd?(double)s1:(double)(s1+s2)/2;
    }
};
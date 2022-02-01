class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        m1 = self.getKth(nums1, 0, m-1, nums2, 0, n-1, (m+n-1)//2)
        m2 = self.getKth(nums1, 0, m-1, nums2, 0, n-1, (m+n)//2)
        return (m1+m2)/2
    def getKth(self, n1, s1, e1, n2, s2, e2, k):
        if s1>e1: return n2[s2+k]
        if s2>e2: return n1[s1+k]
        i1, i2 = s1+(e1-s1+1)//2, s2+(e2-s2+1)//2
        if (i1-s1)+(i2-s2)<k:
            if n1[i1]<n2[i2]: return self.getKth(n1, i1+1, e1, n2, s2, e2, k-(i1-s1)-1)
            else: return self.getKth(n1, s1, e1, n2, i2+1, e2, k-(i2-s2)-1)
        else:
            if n1[i1]<n2[i2]: return self.getKth(n1, s1, e1, n2, s2, i2-1, k)
            else: return self.getKth(n1, s1, i1-1, n2, s2, e2, k)
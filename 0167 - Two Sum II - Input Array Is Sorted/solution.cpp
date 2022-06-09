class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        int l = 0, r = A.size()-1;
        while(l < r){
            if(A[l]+A[r] == target) return {l+1, r+1};
            else if(A[l]+A[r] > target) r--;
            else l++;
        }
        return {};
    }
};
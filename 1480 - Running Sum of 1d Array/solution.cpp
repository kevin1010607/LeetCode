class Solution {
public:
    vector<int> runningSum(vector<int>& A) {
        partial_sum(A.begin(), A.end(), A.begin());
        return A;
    }
};
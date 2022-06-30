class Solution {
public:
    int minMoves2(vector<int>& A) {
        int n = A.size(), res = 0;
        nth_element(A.begin(), A.begin()+(n/2), A.end());
        for(auto i : A) res += abs(i-A[n/2]);
        return res;
    }
};
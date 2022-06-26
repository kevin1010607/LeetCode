class Solution {
public:
    int maximumUniqueSubarray(vector<int>& A) {
        unordered_set<int> s;
        int res = INT_MIN, total = 0, l = 0;
        for(int i = 0; i < A.size(); i++){
            while(s.count(A[i])){
                s.erase(A[l]);
                total -= A[l++];
            }
            s.insert(A[i]);
            total += A[i];
            res = max(res, total);
        }
        return res;
    }
};
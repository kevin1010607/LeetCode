class Solution {
public:
    int findMinMoves(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0), n = A.size();
        if(sum%n) return -1;
        int target = sum/n, move = 0, res = 0;
        for(auto i : A){
            move += i-target;
            res = max({res, abs(move), i-target});
        }
        return res;
    }
};
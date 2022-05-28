class Solution {
public:
    int missingNumber(vector<int>& A) {
        int res = 0;
        for(int i = 0; i <= A.size(); i++) res ^= i;
        for(auto i : A) res ^= i;
        return res;
    }
};
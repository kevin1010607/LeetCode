class Solution {
public:
    int longestConsecutive(vector<int>& A) {
        unordered_map<int, int> m;
        int res = 0;
        for(auto i : A){
            if(m[i]) continue;
            m[i] = m[i+m[i+1]] = m[i-m[i-1]] = m[i+1]+m[i-1]+1;
            res = max(res, m[i]);
        }
        return res;
    }
};
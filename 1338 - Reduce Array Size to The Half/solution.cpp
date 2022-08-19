class Solution {
public:
    int minSetSize(vector<int>& A) {
        int res = 0, n = A.size(), h = n/2;
        vector<int> cnt(n+1);
        unordered_map<int, int> m;
        for(auto i : A) m[i]++;
        for(auto [i, v] : m) cnt[v]++;
        while(h > 0){
            while(cnt[n] == 0) n--;
            res++, cnt[n]--, h -= n;
        }
        return res;
    }
};
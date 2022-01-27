class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s;
        for(int i = 30, mask = 0; i >= 0; i--){
            mask = mask|(1<<i);
            for(auto i : nums) s.insert(mask&i);
            int t = res|(1<<i);
            for(auto i : s) if(s.count(t^i)){res = t; break;}
            s.clear();
        }
        return res;
    }
};
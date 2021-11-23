class UnionFind{
public:
    vector<int> parent;
    UnionFind(int n):parent(n){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool uni(int x, int y){
        int xp = find(x), yp = find(y);
        if(xp == yp) return false;
        parent[yp] = xp;
        return true;
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end())+1;
        UnionFind u(n);
        for(auto i : nums){
            for(int j = 2; j*j <= i; j++){
                if(i%j == 0) u.uni(j, i), u.uni(i, i/j);
            }
        }
        int res = 0;
        unordered_map<int, int> m;
        for(auto i : nums) res = max(res, ++m[u.find(i)]);
        return res;
    }
};
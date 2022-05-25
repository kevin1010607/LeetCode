class MaxBIT{
private:
    vector<int> v;
public:
    MaxBIT(int sz){
        v.resize(sz+1);
    }
    int get(int idx){
        int res = 0;
        for(int i = idx; i > 0; i -= i&-i)
            res = max(res, v[i]);
        return res;
    }
    void update(int idx, int val){
        for(int i = idx; i < v.size(); i += i&-i)
            v[i] = max(v[i], val);
    }
};
class Solution {
private:
    const int BASE = 10001;
public:
    int lengthOfLIS(vector<int>& A) {
        MaxBIT b = MaxBIT(20001);
        for(auto i : A)
            b.update(BASE+i, 1+b.get(BASE+i-1));
        return b.get(20001);
    }
};
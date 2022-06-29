class BIT{
private:
    int n;
    vector<int> v;
public:
    BIT(int size):n(size){
        v.resize(size+1);
    }
    void update(int x, int d){
        for(int i = x+1; i <= n; i += (i&(-i)))
            v[i] += d;
    }
    int query(int x){
        int res = 0;
        for(int i = x+1; i > 0; i -= (i&(-i)))
            res += v[i];
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& A) {
        sort(A.begin(), A.end(), [](auto& a, auto& b){
            return a[0]<b[0] || a[0]==b[0]&&a[1]>b[1]; 
        });
        int n = A.size();
        BIT b(n);
        vector<vector<int>> res(n);
        for(int i = 1; i < n; i++) b.update(i, 1);
        for(int i = 0; i < n; i++){
            int l = 0, r = n-1;
            while(l < r){
                int mid = l+(r-l)/2;
                if(b.query(mid) >= A[i][1]) r = mid;
                else l = mid+1;
            }
            res[l] = A[i];
            b.update(l, -1);
        } 
        return res;
    }
};
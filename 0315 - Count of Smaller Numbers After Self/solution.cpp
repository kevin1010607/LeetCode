#define P pair<int, int>
#define F first
#define S second
class Solution {
private:
    void mergeSort(vector<P>& p, vector<int>& res){
        int n = p.size(), mid = n/2;
        if(n < 2) return;
        vector<P> left(p.begin(), p.begin()+mid), right(p.begin()+mid, p.end());
        mergeSort(left, res); 
        mergeSort(right, res);
        for(int i = n-1; i >= 0; i--){
            if(right.empty() || !left.empty()&&left.back().F>right.back().F)
                p[i] = left.back(), left.pop_back(), res[p[i].S] += right.size();
            else
                p[i] = right.back(), right.pop_back();
        }
    }
public:
    vector<int> countSmaller(vector<int>& A) {
        int n = A.size();
        vector<P> p(n);
        for(int i = 0; i < n; i++) 
            p[i] = {A[i], i}, A[i] = 0;
        mergeSort(p, A);
        return A;
    }
};
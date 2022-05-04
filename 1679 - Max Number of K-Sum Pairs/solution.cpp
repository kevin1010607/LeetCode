class Solution {
public:
    int maxOperations(vector<int>& A, int k) {
        int res = 0;
        unordered_map<int, int> m;
        for(auto i : A){
            if(m.count(k-i)){
                res++, m[k-i]--;
                if(m[k-i] == 0) m.erase(k-i);
            }
            else m[i]++;
        }
        return res;
    }
};
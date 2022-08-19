class Solution {
public:
    bool isPossible(vector<int>& A) {
        unordered_map<int, int> l, r;
        for(auto i : A) l[i]++;
        for(auto i : A){
            if(l[i] == 0) continue;
            l[i]--;
            if(r[i-1]) r[i-1]--, r[i]++;
            else if(l[i+1] && l[i+2]) l[i+1]--, l[i+2]--, r[i+2]++;
            else return false;
        }
        return true;
    }
};
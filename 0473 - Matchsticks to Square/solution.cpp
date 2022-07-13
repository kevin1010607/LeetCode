class Solution {
private:
    bool solve(int idx, int tar, vector<int>& A, vector<int>& now){
        if(idx == A.size()) return now[0]==now[1]&&now[1]==now[2]&&now[2]==now[3];
        for(int i = 0; i < 4; i++){
            bool prune = now[i]+A[idx]>tar;
            for(int j = 0; j < i; j++) 
                if(now[i] == now[j]) prune = true;
            if(prune) continue;
            now[i] += A[idx];
            if(solve(idx+1, tar, A, now)) return true;
            now[i] -= A[idx];
        }
        return false;        
    }
public:
    bool makesquare(vector<int>& A) {
        int total = accumulate(A.begin(), A.end(), 0);
        if(total%4) return false;
        vector<int> now(4);
        sort(A.begin(), A.end(), greater<int>());
        return solve(0, total/4, A, now);
    }
};
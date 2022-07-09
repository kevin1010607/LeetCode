class Solution {
public:
    int maxResult(vector<int>& A, int k) {
        deque<int> q{0};
        for(int i = 1; i < A.size(); i++){
            if(q.front() < i-k) q.pop_front();
            A[i] += A[q[0]];
            while(!q.empty() && A[i]>A[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return A.back();
    }
};
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX, mi = INT_MAX;
        priority_queue<int> q;
        for(auto i : nums){
            int now = i%2?i*2:i;
            q.push(now);
            mi = min(mi, now);
        }
        while(q.size() == nums.size()){
            int ma = q.top(); q.pop();
            res = min(res, ma-mi);
            if(ma%2 == 0) q.push(ma/2), mi = min(mi, ma/2);
        }
        return res;
    }
};
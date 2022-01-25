class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int cnt = 0, res = 0, flag = 1;
        for(auto i : seats){
            if(i) flag = 0;
            cnt = i?0:cnt+1;
            res = max(res, (flag?cnt:(cnt+1)/2));
        }
        return max(res, cnt);
    }
};
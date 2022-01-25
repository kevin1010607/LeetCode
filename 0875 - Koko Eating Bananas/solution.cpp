class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MAX;
        while(l < r){
            int mid = l+(r-l)/2, val = 0;
            for(auto i : piles) val += i/mid+(i%mid?1:0);
            if(val <= h) r = mid;
            else l = mid+1;
        }
        return l;
    }
};
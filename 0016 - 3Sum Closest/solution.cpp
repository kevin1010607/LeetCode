class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), m = INT_MAX, res = -1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            int l = i+1, r = n-1;
            while(l < r){
                int s = nums[i]+nums[l]+nums[r];
                if(s == target) return s;
                if(abs(s-target) < m) m = abs(s-target), res = s;
                s<target?(l++):(r--);
            }
        }
        return res;
    }
};
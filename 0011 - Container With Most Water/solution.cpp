class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, res = 0;
        while(l < r){
            if(height[l] < height[r]) res = max(res, (r-l)*height[l]), l++;
            else res = max(res, (r-l)*height[r]), r--;
        }
        return res;
    }
};
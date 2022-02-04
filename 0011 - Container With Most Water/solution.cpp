class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, res = 0;
        while(l < r){
            int h = min(height[l], height[r]);
            res = max(res, (r-l)*h);
            while(l<r && height[l]<=h) l++;
            while(l<r && height[r]<=h) r--;
        }
        return res;
    }
};
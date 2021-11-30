class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        stack<int> s; s.push(-1);
        for(int i = 0; i <= n; i++){
            int val = i!=n?heights[i]:0;
            while(s.top()!=-1 && heights[s.top()]>=val){
                int l, r = i-1, h = heights[s.top()];
                s.pop();
                l = s.top();
                res = max(res, h*(r-l));
            }
            s.push(i);
        }
        return res;
    }
};
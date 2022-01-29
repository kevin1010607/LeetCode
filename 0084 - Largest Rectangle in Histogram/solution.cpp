class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        stack<int> s;
        for(int i = 0; i <= n; i++){
            int now = i==n?0:heights[i];
            while(!s.empty() && heights[s.top()]>=now){
                int top = s.top(); s.pop();
                int area = heights[top]*(s.empty()?i:i-s.top()-1);
                res = max(res, area);
            }
            s.push(i);
        }
        return res;
    }
};
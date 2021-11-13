class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        vector<int> res(t.size());
        for(int i = t.size()-1; i >= 0; i--){
            while(!s.empty() && t[s.top()]<=t[i]) s.pop();
            res[i] = s.empty()?0:s.top()-i;
            s.push(i);
        }
        return res;
    }
};
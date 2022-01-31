class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(auto c : s){
            if(c=='(' || c=='[' || c=='{') S.push(c);
            else{
                if(S.empty() || !(c-S.top()==2||c-S.top()==1)) return false;
                S.pop();
            }
        }
        return S.empty();
    }
};
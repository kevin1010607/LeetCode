class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {""};
        vector<string> res;
        for(int i = 0; i < (n+1)/2; i++){
            vector<string> l = generateParenthesis(i);
            vector<string> r = generateParenthesis(n-1-i);
            for(auto& p : l){
                for(auto& q : r){
                    res.push_back("("+p+")"+q);
                    if(i != n-1-i) res.push_back("("+q+")"+p);
                }
            }
        }
        return res;
    }
};
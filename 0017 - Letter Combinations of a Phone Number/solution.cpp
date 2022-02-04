class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> m{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res{""}, tmp;
        for(auto d : digits){
            for(auto s : res){
                for(auto c : m[d-'0']){
                    tmp.push_back(s+c);
                }
            }
            res.swap(tmp);
            tmp.clear();
        }
        return res;
    }
};
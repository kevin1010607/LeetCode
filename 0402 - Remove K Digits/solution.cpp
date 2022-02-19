class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for(auto c : num){
            while(k && res!="" && res.back()>c) res.pop_back(), k--;
            if(res!="" || c!='0') res.push_back(c);
        }
        while(res!="" && k--) res.pop_back();
        return res==""?"0":res;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int flag = 1, len = 0;
        for(int i = 0; flag && i<strs[0].size(); i++){
            for(auto& s : strs)
                if(i==s.size() || strs[0][i]!=s[i]){flag = 0; break;}
            if(flag) len++;
        }
        return strs[0].substr(0, len);
    }
};
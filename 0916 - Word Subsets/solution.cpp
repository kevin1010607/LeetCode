class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int cnt[26] = {}, i;
        vector<string> res;
        for(auto& s : B){
            int tmp[26] = {};
            for(auto c : s) tmp[c-'a']++;
            for(i = 0; i < 26; i++)
                cnt[i] = max(cnt[i], tmp[i]);
        }
        for(auto& s : A){
            int tmp[26] = {};
            for(auto c : s) tmp[c-'a']++;
            for(i = 0; i < 26; i++)
                if(tmp[i] < cnt[i]) break;
            if(i == 26) res.push_back(s);
        }
        return res;
    }
};
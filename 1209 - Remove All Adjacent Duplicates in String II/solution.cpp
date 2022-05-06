class Solution {
public:
    string removeDuplicates(string s, int k) {
        int idx = 0, n = s.size();
        vector<int> cnt(n);
        for(int i = 0; i < n; i++, idx++){
            s[idx] = s[i];
            cnt[idx] = (idx>0&&s[idx-1]==s[idx])?cnt[idx-1]+1:1;
            if(cnt[idx] == k) idx -= k;
        }
        return s.substr(0, idx);
    }
};
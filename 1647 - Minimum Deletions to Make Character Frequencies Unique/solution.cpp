class Solution {
public:
    int minDeletions(string s) {
        int res = 0;
        vector<int> cnt(26);
        unordered_set<int> seen;
        for(auto c : s) cnt[c-'a']++;
        for(auto i : cnt){
            while(i>0 && seen.count(i)) res++, i--;
            seen.insert(i);
        }
        return res;
    }
};
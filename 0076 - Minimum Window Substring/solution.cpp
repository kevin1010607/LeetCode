class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128);
        for(auto c : t) m[c]++;
        int l = 0, r = 0, start = -1, len = INT_MAX, cnt = t.size();
        for(r = 0; r < s.size(); r++){
            if(m[s[r]]-- > 0) cnt--;
            while(cnt == 0){
                if(r-l+1 < len) len = r-l+1, start = l;
                if(m[s[l++]]++ == 0) cnt++;
            }
        }
        return start==-1?"":s.substr(start, len);
    }
};
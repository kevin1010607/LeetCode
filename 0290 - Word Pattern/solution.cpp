class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v(26, "");
        unordered_set<string> us;
        int pos = 0, n = pattern.size(), start = 0;
        s += " ";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' ') continue;
            if(pos == n) return false;
            string now = s.substr(start, i-start);
            int id = pattern[pos]-'a'; 
            if(v[id] == ""){
                if(us.count(now)) return false;
                us.insert(now);
                v[id] = now;
            }
            else if(v[id] != now) return false;
            start = i+1, pos++;
        }
        return pos==n;
    }
};
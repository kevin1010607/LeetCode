class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> us;
        int key = 0;
        for(int i = 0; i < s.size(); i++){
            key = (key>>1)|((s[i]-'0')<<(k-1));
            if(i >= k-1) us.insert(key);
        }
        return us.size() == 1<<k;
    }
};
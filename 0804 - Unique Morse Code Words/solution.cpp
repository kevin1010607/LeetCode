#define ll long long
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& A) {
        vector<string> m{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<ll> us;
        for(auto& s : A){
            ll key = 0, p = 1;
            for(auto i : s)
                for(auto j : m[i-'a'])
                    key += (j=='-'?p*2:p), p *= 3;
            us.insert(key);
        }
        return us.size();
    }
};
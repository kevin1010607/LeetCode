class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> m;
        vector<int> res(puzzles.size());
        auto getMask = [](string& s)->int{
            int res = 0;
            for(auto c : s) res |= (1<<(c-'a'));
            return res;
        };
        for(auto& s : words) m[getMask(s)]++;
        for(int i = 0; auto& s : puzzles){
            int mask = getMask(s), cnt = 0, first = (1<<(s[0]-'a'));
            for(int subMask = mask; subMask; subMask = (subMask-1)&mask){
                if(subMask & first) cnt += m[subMask];
            }
            res[i++] = cnt;
        }
        return res;
    }
};
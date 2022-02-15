class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us(wordList.begin(), wordList.end()), h, t;
        if(!us.count(endWord)) return 0;
        h.insert(beginWord);
        t.insert(endWord);
        for(int res = 2; !h.empty()&&!t.empty(); res++){
            if(h.size() > t.size()) swap(h, t);
            unordered_set<string> tmp;
            for(auto s : h){
                for(int i = 0; i < s.size(); i++){
                    char c = s[i];
                    for(char j = 'a'; j <= 'z'; j++){
                        s[i] = j;
                        if(t.count(s)) return res;
                        auto it = us.find(s);
                        if(it != us.end()){
                            tmp.insert(s);
                            us.erase(it);
                        }
                    }
                    s[i] = c;
                }
            }
            swap(h, tmp);
        }
        return 0;
    }
};
class WordDictionary {
private:
    unordered_map<int, vector<string>> m;
    bool match(string& target, string& word){
        for(int i = 0; i < target.size(); i++){
            if(target[i] == '.') continue;
            if(target[i] != word[i]) return false;
        }
        return true;
    }
public:
    WordDictionary() {}
    void addWord(string word) {
        m[word.size()].push_back(word);
    }
    bool search(string word) {
        for(auto& s : m[word.size()]){
            if(match(word, s)) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
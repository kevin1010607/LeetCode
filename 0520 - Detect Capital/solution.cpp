class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = 1; i < word.size(); i++)
            if(isupper(word[i])!=isupper(word[1]) || (islower(word[0])&&isupper(word[i]))) return false;
        return true;
    }
};
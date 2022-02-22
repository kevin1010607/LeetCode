class Solution {
public:
    int titleToNumber(string columnTitle) {
        return accumulate(columnTitle.begin(), columnTitle.end(), 0, [](int n, char c){return n*26+(c-'A'+1);});
    }
};
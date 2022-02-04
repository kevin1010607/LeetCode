class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for(auto c : s){
            switch(c){
                case '(': sk.push(')'); break;
                case '{': sk.push('}'); break;
                case '[': sk.push(']'); break;
                default:
                    if(sk.empty() || c!=sk.top()) return false;
                    else sk.pop();
            }
        }
        return sk.empty();
    }
};
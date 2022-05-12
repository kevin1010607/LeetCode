class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(auto& i : emails){
            string local, domain = i.substr(i.find('@'));
            for(auto c : i){
                if(c=='+' || c=='@') break;
                if(c == '.') continue;
                local += c;
            }
            s.insert(local+domain);
        }
        return s.size();
    }
};
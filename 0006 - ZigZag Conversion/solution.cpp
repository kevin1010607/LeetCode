class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows);
        int row = 0, dir = -1;
        for(auto c : s){
            v[row] += c;
            if(row==0 || row==numRows-1) dir = -dir;
            row += dir;
        }
        string res = "";
        for(auto& c : v) res += c;
        return res;
    }
};
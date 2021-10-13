class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows, "");
        int row = 0, dir = -1;
        for(char c : s){
            v[row] += c;
            if(row==0 || row==numRows-1) dir = -dir;
            row += dir;
        }
        string ret = "";
        for(string st : v) ret += st;
        return ret;
    }
};
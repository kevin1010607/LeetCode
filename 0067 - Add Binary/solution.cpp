class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        for(int i=a.size()-1, j=b.size()-1, c=0; i>=0||j>=0||c; i--, j--, c/=2){
            if(i >= 0) c += a[i]-'0';
            if(j >= 0) c += b[j]-'0';
            res += to_string(c%2);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
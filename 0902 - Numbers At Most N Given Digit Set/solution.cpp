class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        int d = digits.size(), m = num.size(), res = 0;
        for(int i = 1; i < m; i++) res += pow(d, i);
        for(int i = 0; i < m; i++){
            bool e = false;
            for(auto& c : digits){
                if(c[0] < num[i]) res += pow(d, m-i-1);
                else if(c[0] == num[i]) e = true;
            }
            if(!e) return res;
        }
        return res+1;
    }
};
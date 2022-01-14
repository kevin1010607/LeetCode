class Solution {
private:
    bool check(int sign, int res, int d){
        if(sign == 1){
            if(res > INT_MAX/10) return true;
            else if(res==INT_MAX/10 && d>7) return true;
        }
        else{
            if(res < INT_MIN/10) return true;
            else if(res==INT_MIN/10 && d>8) return true;
        }
        return false;
    }
public:
    int myAtoi(string s) {
        int res = 0, sign = 1, flag = 0;
        for(auto c : s){
            if(c==' ' && flag==0) continue;
            else if((c=='+' || c=='-') && flag==0) sign = c=='+'?1:-1, flag = 1;
            else if(c>='0' && c<='9'){
                flag = 1;
                if(check(sign, res, c-'0')){
                    res = sign==1?INT_MAX:INT_MIN;
                    break;
                }
                else res = res*10+sign*(c-'0');
            }
            else break;
        }
        return res;
    }
};
class Solution {
public:
    int calculate(string s) {
        stack<char> op;
        stack<int> num;
        auto pc = [](char c){return c=='*'||c=='/';};
        s += "#";
        for(int i = 0; i < s.size(); i++){
            if(isspace(s[i])) continue;
            if(isdigit(s[i])){
                int now = 0;
                while(isdigit(s[i])) now = 10*now+(s[i++]-'0');
                num.push(now); i--;
            }
            else{
                while(!op.empty() && pc(s[i])<=pc(op.top())){
                    char o = op.top(); op.pop();
                    int num1 = num.top(); num.pop();
                    int num2 = num.top(); num.pop();
                    if(o == '+') num.push(num2+num1);
                    else if(o == '-') num.push(num2-num1);
                    else if(o == '*') num.push(num2*num1);
                    else if(o == '/') num.push(num2/num1);
                }
                op.push(s[i]);
            }
        }
        return num.top();
    }
};
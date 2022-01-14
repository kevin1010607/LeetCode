int check(int sign, int res, int d){
    if(sign == 1){
        if(res > INT_MAX/10) return 1;
        else if(res==INT_MAX/10 && d>7) return 1;
    }
    else{
        if(res < INT_MIN/10) return 1;
        else if(res==INT_MIN/10 && d>8) return 1;
    }
    return 0;
}
int myAtoi(char *s){
    int res = 0, sign = 1, flag = 0;
    for(; *s; s++){
        if(*s==' ' && flag==0) continue;
        else if((*s=='+' || *s=='-') && flag==0) sign = *s=='+'?1:-1, flag = 1;
        else if(*s>='0' && *s<='9'){
            flag = 1;
            if(check(sign, res, *s-'0')){
                res = sign==1?INT_MAX:INT_MIN;
                break;
            }
            else res = res*10+sign*(*s-'0');
        }
        else break;
    }
    return res;
}
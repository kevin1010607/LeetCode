bool isPalindrome(int x){
    long long ret = 0, tmp = x;
    while(tmp > 0) ret = 10*ret+tmp%10, tmp /= 10;
    return ret == x;
}
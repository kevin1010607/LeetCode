double myPow(double x, int n) {
    if(n < 0) return 1/(x*myPow(x, -(n+1)));
    if(n == 0) return 1;
    return myPow(x*x, n/2)*(n%2?x:1);
}
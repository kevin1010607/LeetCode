int numberOfSteps(int n){
    return n?__builtin_popcount(n)+31-__builtin_clz(n):0;
}
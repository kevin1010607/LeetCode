int mirrorReflection(int p, int q){
    p = p&-p, q = q&-q;
    return p>q?2:(p<q?0:1);
}
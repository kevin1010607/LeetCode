int poorPigs(int buckets, int die, int test){
    return ceil(log10(buckets)/log10(test/die+1));
}
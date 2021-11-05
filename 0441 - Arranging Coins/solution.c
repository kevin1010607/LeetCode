int arrangeCoins(int n){
    int l = 0, r = 65535;
    while(l <= r){
        long long mid = (l+r)/2, sum = (mid+1)*mid/2;
        if(sum > n) r = mid-1;
        else if(sum < n) l = mid+1;
        else return mid;
    }
    return l-1;
}
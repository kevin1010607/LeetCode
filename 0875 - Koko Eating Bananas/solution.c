int minEatingSpeed(int* piles, int pilesSize, int h){
    int l = 1, r = 1e9;
    while(l < r){
        int mid = l+(r-l)/2, val = 0;
        for(int i = 0; i < pilesSize; i++)
            val += piles[i]/mid+(piles[i]%mid?1:0);
        if(val <= h) r = mid;
        else l = mid+1;
    }
    return l;
}
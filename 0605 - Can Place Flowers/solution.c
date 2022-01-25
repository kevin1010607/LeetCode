bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int cnt = 0, nn = flowerbedSize;
    for(int i = 0; i < nn; i++){
        if(flowerbed[i]) continue;
        int b1 = i==0?0:flowerbed[i-1];
        int b2 = i==nn-1?0:flowerbed[i+1];
        if(!b1 && !b2) flowerbed[i] = 1, cnt++;
    }
    return cnt >= n;
}
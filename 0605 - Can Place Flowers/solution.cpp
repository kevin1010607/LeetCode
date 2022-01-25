class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0, nn = flowerbed.size();
        for(int i = 0; i < nn; i++){
            if(flowerbed[i] == 1) continue;
            int b1 = i==0?0:flowerbed[i-1];
            int b2 = i==nn-1?0:flowerbed[i+1];
            if(b1==0 && b2==0) flowerbed[i] = 1, cnt++;
        }
        return cnt >= n;
    }
};
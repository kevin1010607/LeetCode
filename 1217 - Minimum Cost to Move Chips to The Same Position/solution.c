#define min(a,b) a<b?a:b
int minCostToMoveChips(int* position, int positionSize){
    int odd = 0, even = 0;
    for(int i = 0; i < positionSize; i++) (position[i]%2)?(odd++):(even++);
    return min(odd, even);
}
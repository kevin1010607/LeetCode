int numPairsDivisibleBy60(int* time, int timeSize){
    int v[60] = {0}, res = 0;
    for(int i = 0; i < timeSize; i++){
        res += v[(60-time[i]%60)%60];
        v[time[i]%60]++;
    }
    return res;
}
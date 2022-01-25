#define max(a,b) (((a)>(b))?(a):(b))
int maxDistToClosest(int* seats, int seatsSize){
    int cnt = 0, res = 0, flag = 1;
    for(int i = 0; i < seatsSize; i++){
        if(seats[i]) flag = 0;
        cnt = seats[i]?0:cnt+1;
        res = max(res, (flag?cnt:(cnt+1)/2));
    }
    return max(res, cnt);
}
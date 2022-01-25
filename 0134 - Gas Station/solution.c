int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int now = 0, total = 0, start = 0;
    for(int i = 0; i < gasSize; i++){
        now += gas[i]-cost[i];
        total += gas[i]-cost[i];
        if(now < 0) start = i+1, now = 0;
    }
    return total>=0?start:-1;
}
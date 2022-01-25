class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, now = 0, total = 0;
        for(int i = 0; i < gas.size(); i++){
            now += gas[i]-cost[i];
            total += gas[i]-cost[i];
            if(now < 0) start = i+1, now = 0;
        }
        return total>=0?start:-1;
    }
};
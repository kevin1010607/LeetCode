class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < 32; i++){
            int c = 0;
            for(int j : nums) if(j&(1<<i)) c++;
            ret |= (c%3)<<i;
        }
        return ret;
    }
};
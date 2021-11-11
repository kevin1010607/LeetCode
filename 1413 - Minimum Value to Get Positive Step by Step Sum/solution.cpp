class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum{}, m{};
        for(auto& num : nums){
            sum += num;
            m = min(m, sum);
        }
        return -m+1;
    }
};
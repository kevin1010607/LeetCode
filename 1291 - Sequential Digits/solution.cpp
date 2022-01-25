class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int l = to_string(low).size();
        int r = to_string(high).size();
        vector<int> res;
        for(int i = l; i <= r; i++){
            for(int j = 0; j+i <= 9; j++){
                int now = stoi(s.substr(j, i));
                if(now>=low && now<=high) res.push_back(now);
            }
        }
        return res;
    }
};
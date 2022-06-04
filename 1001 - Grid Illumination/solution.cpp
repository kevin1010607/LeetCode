class Solution {
private:
    struct pairHash{
        int operator()(const pair<int, int>& a) const {return a.first^a.second;}
    };
public:
    vector<int> gridIllumination(long long n, vector<vector<int>>& L, vector<vector<int>>& Q) {
        vector<int> res;
        unordered_set<pair<int, int>, pairHash> s;
        unordered_map<int, int> row, col, dia1, dia2;
        for(auto& p : L){
            int x = p[0], y = p[1];
            if(s.insert({x, y}).second)
                row[x]++, col[y]++, dia1[x+y]++, dia2[x-y]++;
        }
        for(auto& p : Q){
            int x = p[0], y = p[1];
            res.push_back(row.count(x)||col.count(y)||dia1.count(x+y)||dia2.count(x-y));
            for(int i = x-1; i <= x+1; i++){
                for(int j = y-1; j <= y+1; j++){
                    if(s.erase({i, j})){
                        if(!--row[i]) row.erase(i);
                        if(!--col[j]) col.erase(j);
                        if(!--dia1[i+j]) dia1.erase(i+j);
                        if(!--dia2[i-j]) dia2.erase(i-j);
                    }
                }
            }
        }
        return res;
    }
};
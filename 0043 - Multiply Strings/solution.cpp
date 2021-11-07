class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<int> v(n1+n2, 0);
        for(int i = n1-1; i >= 0; i--){
            for(int j = n2-1; j >= 0; j--){
                v[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                v[i+j] += v[i+j+1]/10;
                v[i+j+1] %= 10;
            }
        }
        int id = 0;
        while(v[id] == 0) id++;
        string s(n1+n2-id, 0);
        for(int i = 0; i < n1+n2-id; i++) s[i] = '0'+v[i+id];
        return s;
    }
};
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> m;
        m[1000]="M", m[500]="D", m[100]="C", m[50]="L", m[10]="X", m[5]="V", m[1]="I";
        string res = "";
        int p = 1;
        while(num){
            int id = (num%10)*p;
            while(id){
                if(m.count(id)) res = m[id]+res, id = 0;
                else if(m.count(id+p)) res = m[p]+m[id+p]+res, id = 0;
                else res = m[p]+res, id -= p;
            }
            num /= 10, p *= 10;
        }
        return res;
    }
};
#define BASE 31
#define ull unsigned long long
class Solution {
public:
    unordered_set<ull> st;
    int find(string &s, int L, ull pow){
        st.clear();
        ull hash = 0;
        for(int i = 0; i < L; i++) hash = hash*BASE+(s[i]-'a');
        st.insert(hash);
        for(int i = L; i < s.size(); i++){
            hash = (hash-(s[i-L]-'a')*pow)*BASE+(s[i]-'a');
            if(st.find(hash) != st.end()) return i-L+1;
            st.insert(hash);
        }
        return -1;
    }
    string longestDupSubstring(string s) {
        int n = s.size(), l = 0, r = n-1;
        vector<ull> power(n, 1);
        for(int i = 1; i < n; i++) power[i] = power[i-1]*BASE;
        while(l < r){
            int mid = (l+r)/2;
            if(find(s, mid+1, power[mid]) == -1) r = mid;
            else l = mid+1;
        }
        return l==0?"":s.substr(find(s, l, power[l-1]), l);
    }
};
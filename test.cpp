#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> m;
        for(auto &s:arr){
            if(m.find(s) != m.end()) m[s]++;
            else m.insert({s,1});
        }
        int idx = 1;
        for(auto &s:arr){
            if(m[s] == 1){
                if(idx == k) return s;
                idx++;
            }
        }
        return "";
    }
};

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int num = s.size();
        vector<int> L(num), R(num), sum(num);
        sum[0] = 0;
        for(int i = 1; i < num; i++){
            if(s[i] == '|') sum[i] = sum[i-1]+1;
            else sum[i] = sum[i-1];
        }
        int preL = -1;
        for(int i = 0; i < num; i++){
            if(s[i] == '*') L[i] = preL;
            else L[i] = preL = i;
        }
        int preR = num;
        for(int i = num-1; i >= 0; i--){
            if(s[i] == '*') R[i] = preR;
            else R[i] = preR = i;
        }
        vector<int> ret(q.size());
        for(int i = 0; i < q.size(); i++){
            int l = R[q[i][0]], r = L[q[i][1]];
            if(l==num || r==-1 || l>=r) ret[i] = 0;
            else ret[i] = r-l-1-(sum[r]-sum[l]-1);
        }
        return ret;
    }
};

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ret = 0, max1 = 0;
        sort(events.begin(), events.end());
        map<int, int> m;
        for(auto it = events.rbegin(); it != events.rend(); it++){
            max1 = max(max1, (*it)[2]);
            m[(*it)[0]] = max1;
            auto u = m.upper_bound((*it)[1]);
            if(u == m.end()) ret = max(ret, max1);
            else ret = max(ret, (*it)[2]+(*u).second);
        }
        return ret;
    }
};

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++){
            if(i%10 == nums[i]) return i;
        }
        return -1;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mi = 0x3f3f3f3f, ma = -1, idx = 2, prev = -1, first;
        if(!head) return {-1, -1};
        if(!head->next) return {-1, -1};
        int pre = head->val;
        head = head->next;
        while(head->next){
            if(head->val<pre&&head->val<head->next->val || head->val>pre&&head->val>head->next->val){
                if(prev != -1){
                    mi = min(mi, idx-prev);
                    ma = max(ma, idx-prev);
                }
                else first = idx;
                prev = idx;
            }
            idx++;
            pre = head->val;
            head = head->next;
        }
        ma = prev-first;
        if(mi==0x3f3f3f3f) return {-1, -1};
        else return {mi, ma};
    }
};

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
    }
};


class Solution {
public:
    int countVowelSubstrings(string word) {
        int ret = 0;
        for(int i = 0; i < word.size(); i++){
            for(int j = 1; j <= word.size()-i; j++){
                int m[26] = {0};
                //cout << word.substr(i, j) << endl;
                for(int k = i; k < i+j; k++){
                    m[word[k]-'a']++;
                }
                bool t = true;
                for(int l = 0; l < 26; l++){
                    if(l=='a'-'a' || l=='e'-'a' || l=='i'-'a' || l=='o'-'a' || l=='u'-'a'){
                        if(m[l] == 0){t = false; break;}
                    }
                    else if(m[l]!=0) {t=false; break;}
                }
                if(t) ret++;
            }
        }
        return ret;
    }
};

class Solution {
public:
    long long countVowels(string word) {
        long long ret = 0;
        for(int i = 1; i <= word.size(); i++){
            if(word[i-1]=='a'||word[i-1]=='e'||word[i-1]=='i'||word[i-1]=='o'||word[i-1]=='u'){
                ret += (word.size()-i+1)*i;
            }
        }
        return ret;
    }
};

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> s(26,0);
        for(auto c:word1) s[c-'a']++;
        for(auto c:word2) s[c-'a']--;
        for(auto i:s){
            if(i>3 || i <-3){
                return false;
            }
        }
        return true;
    }
};

class Robot {
public:
    int n, m, r;
    int x, y;
    vector<string> st;
    int dir;
    Robot(int width, int height) {
        st.push_back("East");
        st.push_back("North");
        st.push_back("West");
        st.push_back("South");
        dir = 0;
        x = y = 0;
        n = width, m = height;
        r = (width+height-2)*2;
    }
    
    void move(int num) {
        static int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
        num %= r;
        if(num==0){
            if(x==0&&y==0) dir = 3;
            if(x==0&&y==m-1) dir = 2;
            if(x==n-1&&y==0) dir = 0;
            if(x==n-1&&y==m-1) dir = 1;
        }
        for(int i = 0; i < num; i++){
            int nx = x+dx[dir], ny = y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m){
                dir = (dir+1)%4;
                i--;
            }
            else x = nx, y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return st[dir];
    }
};

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
        vector<int> res(q.size(), 0);
        sort(items.begin(), items.end());
        map<int, int> m;
        int M = -1;
        for(auto& i:items) {
            if(i[1] > M){
                M = i[1];
                m[i[0]] = i[1];
            }
        }
        int i = 0;
        for(auto p:q){
            auto k = m.lower_bound(p);
            if(k==m.end() || k->first>p) k--;
            if(k->first<=p) res[i] = k->second;
            i++;
        }
        return res;
    }
};


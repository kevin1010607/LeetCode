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

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = 0;
        for(int i = 0; i < colors.size(); i++){
            for(int j = i+1; j < colors.size(); j++){
                if(colors[i] != colors[j]) res = max(res, j-i);
            }
        }
        return res;
    }
};

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int res = 0, now = capacity;
        for(int i = 0; i < plants.size(); i++){
            if(now >= plants[i]){
                now -= plants[i];
                res++;
            }
            else{
                res += (i+i+1);
                now = capacity-plants[i];
            }
        }
        return res;
    }
};

class RangeFreqQuery {
public:
    vector<pair<int, int>> v;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            v.emplace_back(arr[i], i);
        }
        sort(v.begin(), v.end());
    }
    
    int query(int left, int right, int value) {
        pair<int, int> p1 = make_pair(value, left), p2 = make_pair(value, right);
        auto l = lower_bound(v.begin(), v.end(), p1);
        auto r = upper_bound(v.begin(), v.end(), p2);
        return r-l;
    }
};

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> a, b;
        set<string> st;
        for(auto &s : words1) {a[s]++; st.insert(s);}
        for(auto &s : words2) {b[s]++; st.insert(s);}
        int res = 0;
        for(auto &s : st){
            if(a[s] == 1 && b[s] == 1) res++;
        }
        return res;
    }
};

class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        int res = 0;
        if(s[0] == 'H'){
            if(n==1 || s[1]=='H') return -1;
            s[1] = 'B';
        }
        for(int i = 1; i < n-1; i++){
            if(s[i] != 'H' ||s[i-1] == 'B') continue;
            if(s[i+1] == 'H' && s[i-1] == 'H') return -1;
            if(s[i+1] == 'H' && s[i-1] == '.') s[i-1] = 'B';
            else s[i+1] = 'B';
        }
        if(s[n-1]=='H'){
            if(s[n-2] == 'H') return -1;
            else s[n-2] = 'B';
        }
        for(int i = 0; i < n; i++) if(s[i] == 'B') res++;
        cout << s << endl;
        return res;
    }
};

class Solution {
public:
    int minCost(vector<int>& sP, vector<int>& hP, vector<int>& rowC, vector<int>& colC) {
        int res(0);
        if(sP[0] <= hP[0]) for(int i = sP[0]+1; i <= hP[0] ; i++) res += rowC[i];
        else for(int i = hP[0]; i < sP[0]; i++) res += rowC[i];
        if(sP[1] <= hP[1]) for(int i = sP[1]+1; i <= hP[1] ; i++) res += colC[i];
        else for(int i = hP[1]; i < sP[1]; i++) res += colC[i];
        return res;
    }
};

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int idx = 0;
        for(auto i : nums){
            if(i == target) res.push_back(idx);
            idx++;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1);
        dp[0] = 0;
        for(int i = 1; i < n+1; i++){
            dp[i] = dp[i-1]+nums[i-1];
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            if(i-k<0 || i+k>=n) res[i] = -1;
            else res[i] = (dp[i+k+1]-dp[i-k])/(2*k+1);
        }
        return res;
    }
};

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int ma(INT_MIN), mi(INT_MAX), i1(-1), i2(-1);
        for(int i = 0; i < n; i++){
            if(nums[i] > ma) ma = nums[i], i1 = i;
            if(nums[i] < mi) mi = nums[i], i2 = i;
        }
        cout << i1 << " " << i2 << "\n";
        return min(min(max(i1+1,i2+1), max(n-i1, n-i2)), min(i1+1, n-i1)+min(i2+1, n-i2));
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int first) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<bool> known(n, false);
        auto cmp = [](vector<int>& a, vector<int>& b){return a[2]<b[2];};
        sort(meet.begin(), meet.end(), cmp);
        known[0] = known[first] = true;
        vector<set<vector<int>>> tmp;
        int pre = -1, idx = 0;
        for(int i = 0; i < meet.size(); i++){
            if(meet[i][2] == pre) tmp[idx-1].insert(meet[i]);
            else {tmp.push_back(set<vector<int>> {meet[i]}); idx++;}
            pre = meet[i][2];
        }
        /*for(auto v1 : tmp){
            for(auto v2: v1){
                for(auto v3 : v2){
                    cout << v3 << " ";
                }
                cout << "|";
            }
            cout << "\n";
        }
        cout << "\n";*/
        
        for(auto& v1: tmp){
            //vector<int> k;
            while(true){
                int flag = 1;
                set<vector<int>> ss;
                for(auto& v2 : v1){
                    if(known[v2[0]]==true && known[v2[1]]==true) ss.insert(v2);
                    if(known[v2[0]]==true || known[v2[1]]==true){
                        if(known[v2[0]]==false || known[v2[1]]==false) flag = 0;
                        known[v2[0]] = known[v2[1]] = true;
                    }
                }
                for(auto& vv : ss) v1.erase(vv);
                if(flag == 1) break;
            }
            
            //for(auto i : k) known[i] = true;
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++) if(known[i] == true) res.push_back(i);
        return res;
    }
};

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        set<int> ss;
        int n = digits.size();
        for(int i = 0; i < n; i++){
            if(digits[i] == 0) continue;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j) continue;
                    if(digits[k]%2) continue;
                    int s = 100*digits[i]+10*digits[j]+digits[k];
                    ss.insert(s);
                }
            }
        }
        for(auto i : ss) res.push_back(i);
        return res;
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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode *now = head;
        int len = 0;
        while(now){
            now = now->next;
            len++;
        }
        len  = len/2-1;
        now = head;
        while(len--) now = now->next;
        ListNode *tmp = now->next;
        now->next = tmp->next;
        delete tmp;
        return head;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode *root, int val, vector<char>& s){
        if(!root) return 0;
        if(root->val == val) return 1;
        s.push_back('L');
        int a = find(root->left, val, s);
        if(a) return 1;
        s.pop_back();
        s.push_back('R');
        int b = find(root->right, val, s);
        if(b) return 1;
        s.pop_back();
        return {};
    }
    string getDirections(TreeNode* root, int v1, int v2) {
        vector<char> vv1, vv2;
        find(root, v1, vv1);
        find(root, v2, vv2);
        int n = vv1.size(), m = vv2.size();
        int idx = 0;
        while((idx<n&&idx<m) && vv1[idx]==vv2[idx]) idx++;
        string s1 = "", s2 = "";
        for(int i = 0; i < n-idx; i++) s1 += "U";
        for(int i = idx; i < m; i++){
            if(vv2[i] == 'L') s2 += "L";
            else s2 += "R";
        }
        s1 += s2;
        return s1;
    }
};

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res, tmp(nums);
        for(int i = 0; i < k; i++){
            int M = INT_MIN, id = -1;
            for(int j = 0; j < tmp.size(); j++){
                if(M < tmp[j]) M = tmp[j], id = j;
            }
            tmp[id] = INT_MIN;
        }
        for(int i = 0; i < tmp.size(); i++){
            if(tmp[i] == INT_MIN) res.push_back(nums[i]);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int t) {
        int n = s.size();
        vector<int> dp1(n, 0), dp2(n, 0), res;
        int last = 0;
        for(int i = 1; i < n; i++){
            if(s[i]<=s[i-1]) last++;
            else last = 0;
            dp1[i] = last;
        }
        last = 0;
        for(int i = n-2; i >= 0; i--){
            if(s[i]<=s[i+1]) last++;
            else last = 0;
            dp2[i] = last;
        }
        for(int i = 0; i < n; i++){
            if(dp1[i]>=t && dp2[i]>=t) res.push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    bool connect(vector<int>& a, vector<int>& b){
        long long a0 = a[0], a1 = a[1], a2 = a[2], b0 = b[0], b1 = b[1], b2 = b[2];
        long long rr = (b0-a0)*(b0-a0)+(b1-a1)*(b1-a1);
        long long r = a2*a2;
        return r >= rr;
    }
    int dfs(int id, vector<vector<int>>& b, vector<bool>& used){
        used[id] = true;
        int res = 1;
        for(int i = 0; i < b.size(); i++){
            if(used[i]) continue;
            if(connect(b[id], b[i])){
                res += dfs(i, b, used);
            }
        }
        return res;
    }
    int maximumDetonation(vector<vector<int>>& b) {
        int n = b.size(), res = 0;
        for(int i = 0; i < n; i++){
            vector<bool> used(n, false);
            res = max(res, dfs(i, b, used));
            cout << res << i << endl;
        }
        return res;
    }
};

class SORTracker {
public:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator it;
    SORTracker() {}
    void add(string name, int score) {
        auto [newit, b] = s.insert({-score, name});
        if(s.size() == 1) it = s.begin();
        else if(*newit < *it) advance(it, -1);
    }
    string get() {
        string res = (*it).second;
        advance(it, 1);
        return res;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */

class Solution {
public:
    int countPoints(string rings) {
        vector<int> r(10), g(10), b(10);
        for(int i = 0; i < rings.size(); i+=2){
            if(rings[i] == 'R') r[rings[i+1]-'0']++;
            if(rings[i] == 'G') g[rings[i+1]-'0']++;
            if(rings[i] == 'B') b[rings[i+1]-'0']++;
        }
        int res = 0;
        for(int i = 0; i < 10; i++){
            if(r[i]>0 && g[i]>0 && b[i]>0) res++;
        }
        return res;
    }
};



class Solution {
public:
    bool plant(int& now, int c, int p){
        if(now >= p){
            now -= p;
            return false;
        }
        else{
            now = c-p;
            return true; 
        }
    }
    int minimumRefill(vector<int>& p, int cA, int cB) {
        int i = 0, j = p.size()-1, res = 0;
        int nowa = cA, nowb = cB;
        while(i < j){
            if(plant(nowa, cA, p[i])) res++;
            if(plant(nowb, cB, p[j])) res++;
            i++, j--;
        }
        if(i == j){
            if(nowa >= nowb) {if(plant(nowa, cA, p[i])) res++;}
            else if(plant(nowb, cB, p[i])) res++;
        }
        return res;
    }
};

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto& s : words){
            int l = 0, r = s.size()-1;
            bool flag = true;
            while(l < r){
                if(s[l] != s[r]) {flag = false; break;}
                l++, r--;
            }
            if(flag) return s;
        }
        return "";
    }
};

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int start = 0;
        if(spaces[0] == 0) res += " ", start++;
        int next = start==spaces.size()?s.size():spaces[start];
        res += s.substr(0, next);
        for(int i = start; i < spaces.size(); i++){
            res += " ";
            int next = i==spaces.size()-1?s.size():spaces[i+1];
            res += s.substr(spaces[i], next-spaces[i]);
        }
        return res;
    }
};

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 1, cnt = 1;
        for(int i = 1; i < prices.size(); i++){
            cnt = prices[i]==prices[i-1]-1?cnt+1:1;
            res += cnt;
        }
        return res;
    }
};

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int res = 0;
        for(int i = 0; i < k; i++){
            int len = 1;
            vector<int> v{arr[i]};
            for(int j = i+k; j < arr.size(); j += k){
                auto pos = upper_bound(v.begin(), v.end(), arr[j]);
                if(pos == v.end()) v.push_back(arr[j]);
                else *pos = arr[j];
                len++;
            }
            res += len-v.size();
        }
        return res;
    }
};

class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num==0 || num%10!=0;
    }
};

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
        static int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
        static char c[] = {'D','R','U','L'};
        for(int i = 0; i < s.size(); i++){
            int x = startPos[0], y = startPos[1], cnt = 0;
            for(int j = i; j < s.size(); j++){
                for(int i = 0; i < 4; i++) if(s[j] == c[i]) x += dx[i], y += dy[i];
                if(x<0||x>=n||y<0||y>=n) break;
                cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<vector<int>> v(100005);
        for(int i = 0; i < arr.size(); i++){
            v[arr[i]].push_back(i);
        }
        vector<bool> flag(100005, false);
        vector<vector<long long>> pre(100005);
        vector<long long> res(arr.size(), 0);
        for(int i = 0; i < arr.size(); i++){
            if(!flag[arr[i]]){
                pre[arr[i]].push_back(v[arr[i]][0]);
                for(int j = 1; j < v[arr[i]].size(); j++){
                    pre[arr[i]].push_back(pre[arr[i]][j-1]+v[arr[i]][j]);
                }
                flag[arr[i]] = true;
            }
            auto a = lower_bound(v[arr[i]].begin(), v[arr[i]].end(), i);
            long long l = a-v[arr[i]].begin(), r = (v[arr[i]].end()-a)-1;
            long long aa = l*i-(l==0?0:pre[arr[i]][l-1]);
            long long bb = (pre[arr[i]][pre[arr[i]].size()-1]-pre[arr[i]][l])-r*i;
            res[i] = aa+bb;
        }
        return res;
    }
};


class Solution {
public:
    bool checkString(string s) {
        for(int i = 0; i < s.size()-1; i++){
            if(s[i]=='b' && s[i+1]=='a') return false;
        }
        return true;
    }
};

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        bool first = true;
        int pre = 0, res = 0;
        for(auto& s : bank){
            int cnt = 0;
            for(auto c : s) if(c == '1') cnt++;
            if(cnt == 0) continue;
            if(first) pre = cnt, first = false;
            else res += pre*cnt, pre = cnt;
        }
        return res;
    }
};

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(), a.end());
        long long tmp = mass;
        for(auto i : a){
            if(tmp >= i) tmp += i;
            else return false;
        }
        return true;
    }
};


class Solution {
public:
    string capitalizeTitle(string title) {
        for(auto& c : title) if(c>='A'&&c<='Z') c = c-'A'+'a';
        if(title.size()<3) return title;
        if(title[0]!=' '&&title[1]!=' '&&title[2]!=' ')
            title[0] = title[0]-'a'+'A';
        for(int i = 0; i < title.size()-3; i++){
            if(title[i]==' '&&title[i+1]!=' '&&title[i+2]!=' '&&title[i+3]!=' ')
                title[i+1] = title[i+1]-'a'+'A';
        }
        return title;
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
    int pairSum(ListNode* head) {
        vector<int> v(1, head->val);
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            v.push_back(slow->val);
        }
        int res = 0, idx = v.size()-1;
        while(slow->next){
            slow = slow->next;
            res = max(res, v[idx--]+slow->val);
        }
        return res;
    }
};

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int t[26][26] = {};
        for(auto& s : words) t[s[0]-'a'][s[1]-'a']++;
        int p = 0, res = 0, flag = 0;
        for(int i = 0; i < 26; i++){
            for(int j = i+1; j < 26; j++){
                p += min(t[i][j], t[j][i]);
            }
        }
        for(int i = 0; i < 26; i++){
            p += t[i][i]/2;
            if(t[i][i]%2) flag = 1;
        }
        return p*4+flag*2;
    }
};


class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int H, int W) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1)), v(m+2, vector<int>(n+2));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+grid[i-1][j-1];
            }
        }
        for(int i = 1; i <= m-H+1; i++){
            for(int j = 1; j <= n-W+1; j++){
                if(grid[i-1][j-1] == 1) continue;
                int now = dp[i+H-1][j+W-1]-dp[i+H-1][j-1]-dp[i-1][j+W-1]+dp[i-1][j-1];
                if(now == 0) v[i][j]++, v[i][j+W]--, v[i+H][j]--, v[i+H][j+W]++;
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                v[i][j] += v[i][j-1]+v[i-1][j]-v[i-1][j-1];
                if(v[i][j]==0 && grid[i-1][j-1] == 0) return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.size();
        int v1[105][105] = {}, v2[105][105] = {};   
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(++v1[i][matrix[i][j]] > 1) return false;
                if(++v2[j][matrix[i][j]] > 1) return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1);
        for(int i = 1; i <= n; i++) v[i] = v[i-1]+nums[i-1];
        int t = v[n], M = 0;
        for(int i = 1; i <= n; i++){
            if(i <= n-t+1) M = max(M, v[i+t-1]-v[i-1]);
            else M = max(M, v[n]-v[i-1]+v[t-(n-i+1)]);
        }
        
        return t-M;
    }
};

class Solution {
public:
    int ss(bitset<26> b){
        int res = 0;
        for(int i = 0; i < 26; i++) res |= (b[i]<<i);
        return res;
    }
    int wordCount(vector<string>& sW, vector<string>& tW) {
        int n = sW.size(), res = 0;
        bitset<100000000> b;
        for(auto& s : sW){
            bitset<26> now;
            for(auto c : s) now[c-'a'] = 1;
            for(int i = 0; i < 26; i++){
                bitset<26> tmp(now);
                if(now[i] == 0) tmp[i] = 1, b[ss(tmp)] = 1;
            }
        }
        for(auto&s : tW){
            int tmp = 0;
            for(auto c : s) tmp |= (1<<(c-'a'));
            if(b[tmp] == 1) res++;
        }
        return res;
    }
};

class Solution {
public:
    int earliestFullBloom(vector<int>& pT, vector<int>& gT) {
        int n = pT.size(), res = 0, total = -1;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            total += pT[i];
            v[i].first = gT[i];
            v[i].second = pT[i];
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++){
            res = max(res, total+v[i].first+1);
            total -= v[i].second;
        }
        return res;
    }
};

class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int, int> m;
        int ma = INT_MIN, mi = INT_MAX;
        for(auto i : nums) m[i]++, ma = max(ma, i), mi = min(mi, i);
        int res = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            if((*it).first==ma || (*it).first==mi) continue;
            res += (*it).second;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int idx1 = 0, idx2 = 1;
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) res[idx1] = nums[i], idx1 += 2;
            if(nums[i] < 0) res[idx2] = nums[i], idx2 += 2;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int a = i==0?(-1e7):nums[i-1];
            int b = i==nums.size()-1?(1e7):nums[i+1];
            if(nums[i]-a>1 && b-nums[i]>1) res.push_back(nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int res = 0, n = statements.size(), s = pow(2, n);
        for(int i = 0; i < s; i++){
            bool flag = true;
            int cnt = 0;
            vector<int> tmp(n);
            for(int j = 0; j < n; j++){
                tmp[j] = ((1<<j)&i)>>j;
                if(tmp[j] == 1) cnt++;
            }
            for(int x = 0; x < n; x++){
                for(int y = 0; y < n; y++){
                    if(statements[x][y] == 2) continue;
                    if(statements[x][y] == 0){
                        if(tmp[x]==1 && tmp[y]==1) {flag = false; break;}
                    }
                    if(statements[x][y] == 1){
                        if(tmp[x]==1 && tmp[y]==0) {flag = false; break;}
                    }
                }
                if(!flag) break;
            }
            
            if(flag) res = max(res, cnt);
        }
        return res;
    }
};

class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        sort(nums.begin(), nums.end());
        for(auto i : nums){
            if(i == o) o *= 2;
        }
        return o;
    }
};

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size(), M = -1;
        vector<int> dp(n+1), res;
        for(int i = 1; i <= n; i++) dp[i] = dp[i-1]+nums[i-1];
        for(int i = 0; i <= n; i++){
            int now = (i-dp[i])+(dp[n]-dp[i]);
            if(now == M) res.push_back(i);
            else if(now > M) {res.clear(); res.push_back(i); M = now;}
        }
        return res;
    }
};

class Solution {
public:
    string subStrHash(string s, int p, int m, int k, int h) {
        long long now = 0, pp = 1;
        vector<int> res(s.size()-k+1);
        for(int i = s.size()-k; i < s.size(); i++){
            now = (now+(s[i]-'a'+1)*pp)%m;
            if(i != s.size()-1) pp = (pp*p)%m;
        }
        res[s.size()-k] = now;
        for(int i = s.size()-k-1; i >= 0; i--){
            now = (now-((s[i+k]-'a'+1)*pp)%m+m)%m;
            now = (now*p)%m;
            now = (now+(s[i]-'a'+1))%m;
            res[i] = now;
        }
        for(int i = 0; i < res.size(); i++){
            if(res[i] == h) return s.substr(i, k);
        }
        return "";
    }
};

class Solution {
private:
    unordered_map<int, int> um;
    unordered_set<int> us;
    int hash(string& s){
        int res = 0;
        for(auto c : s) res |= (1<<(c-'a'));
        return res;
    }
    int dfs(int val){
        us.insert(val);
        int res = um[val];
        for(int i = 0; i < 26; i++){
            int h = val^(1<<i);
            if(us.count(h) || !um.count(h)) continue;
            res += dfs(h);
        }
        for(int i = 0; i < 26; i++){
            if(!(val&(1<<i))) continue;
            int now = val^(1<<i);
            for(int j = 0; j < 26; j++){
                if(now&(1<<j)) continue;
                int h = now^(1<<j);
                if(us.count(h) || !um.count(h)) continue;
                res += dfs(h);
            }
        }
        return res;
    }
public:
    vector<int> groupStrings(vector<string>& words) {
        vector<int> res(2);
        for(auto& s : words) um[hash(s)]++;
        for(auto&[v, n] : um){
            if(us.count(v)) continue;
            res[1] = max(res[1], dfs(v));
            res[0]++;
        }
        return res;
    }
};

class Solution {
public:
    int minimumSum(int num) {
        vector<int> a(4);
        for(int i = 0; i < 4; i++) a[i] = num%10, num /= 10;
        sort(a.begin(), a.end());
        int p = a[0]*10+a[3], q = a[1]*10+a[2];
        return p+q;
    }
};

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int l = 0, e = 0, r = 0;
        vector<int> res(nums.size());
        for(auto i : nums){
            if(i < pivot) l++;
            else if(i == pivot) e++;
            else r++;
        }
        int i1 = 0, i2 = i1+l, i3 = i2+e;
        for(auto i : nums){
            if(i < pivot) res[i1++] = i;
            else if(i == pivot) res[i2++] = i;
            else res[i3++] = i;
        }
        return res;
    }
};

class Solution {
public:
    int minCostSetTime(int startAt, int mC, int pC, int tS) {
        vector<int> v;
        if(tS < 6000){
            int m = tS/60, s = tS%60;
            v.push_back(m*100+s);
            if(s<=39 && m>=1) v.push_back((m-1)*100+s+60);
        }
        else{
            int m = 99, s = tS-99*60;
            v.push_back(m*100+s);
        }
        int res = INT_MAX;
        for(auto i : v){
            string ss = to_string(i);
            int now = ss.size()*pC;
            if(startAt != (ss[0]-'0')) now += mC;
            char cc = ss[0];
            for(int i = 1; i < ss.size(); i++){
                if(ss[i] != cc) now += mC;
                cc = ss[i];
            }
            res = min(res, now);
        }
        return res;
    }
};

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> L;
        priority_queue<int, vector<int>, greater<int>> R;
        long long n = nums.size(), N = n/3, l = 0, r = 0, res = LLONG_MAX;
        vector<long long> v(n);
        for(int i = n-1; i >= N; i--){
            R.push(nums[i]);
            r += nums[i];
            if(R.size() > N){
                r -= R.top();
                R.pop();
            }
            if(R.size() == N) v[i] = r;
        }
        for(int i = 0; i < n-N; i++){
            L.push(nums[i]);
            l += nums[i];
            if(L.size() > N){
                l -= L.top();
                L.pop();
            }
            if(L.size() == N) res = min(res, l-v[i+1]);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> a, b;
        for(int i = 0; i < nums.size(); i++){
            if(i%2) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        sort(b.begin(), b.end());
        int idx1 = 0, idx2 = 0;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(i%2) res.push_back(a[idx1++]);
            else res.push_back(b[idx2++]);
        }
        return res;
    }
};

class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> s;
        int flag = 1;
        if(num < 0)flag = 0, num = -num;
        if(num == 0) return 0;
        while(num) {s.push_back(num%10); num /= 10;}
        sort(s.begin(), s.end());
        long long res = 0;
        if(flag){
            int id = 0;
            while(s[id]==0) id++;
            res = s[id];
            s.erase(s.begin()+id);
            for(auto i : s) res = 10*res+i;
            
        }
        else{
            int id = 0;
            while(s[id]==0) id++;
            res = -s.back();
            s.pop_back();
            for(int i = s.size()-1; i >= 0; i--) res = 10*res-s[i];
        }
        return res;
    }
};

class Bitset {
public:
    vector<int> v;
    int sum = 0;
    int f = 0;
    Bitset(int size) {
        v = vector<int>(size, 0);
    }
    
    void fix(int idx) {
        if(v[idx]^f == 0) sum++, v[idx] ^= 1;
    }
    
    void unfix(int idx) {
        if(v[idx]^f == 1) sum--, v[idx] ^= 1;
    }
    
    void flip() {
        f ^= 1;
        sum = v.size()-sum;
    }
    
    bool all() {
        return sum == v.size();
    }
    
    bool one() {
        return sum > 0;
    }
    
    int count() {
        return sum;
    }
    
    string toString() {
        string s;
        for(auto i : v) s += '0'+i^f;
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */


class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;
        if(num1 < num2) swap(num1, num2);
        while(num2){
            int tmp = num1;
            num1 = num2;
            num2 = tmp-num2;
            if(num1 < num2) swap(num1, num2);
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        unordered_map<int, int> m1, m2;
        for(int i = 0; i < n; i += 2) m1[nums[i]]++;
        for(int i = 1; i < n; i += 2) m2[nums[i]]++;
        int res = 0, a1 = 0, a2 = 0, b1 = 0, b2 = 0, a = 0, b = 0;
        for(auto& [i, v] : m1){
            if(v > a1) a2 = a1, a1 = v, a = i;
            else if(v > a2) a2 = v;
        }
        for(auto& [i, v] : m2){
            if(v > b1) b2 = b1, b1 = v, b = i;
            else if(v > b2) b2 = v;
        }
        if(a != b) res = n-a1-b1;
        else res = n-max({a1+b2, a1+a2, b1+a2, b1+b2});
        return res;
    }
};

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long n = beans.size(), res = LLONG_MAX;
        long long s = accumulate(beans.begin(), beans.end(), 0L);
        sort(beans.begin(), beans.end());
        for(int i = 0; i < n; i++) res = min(res, s-(n-i)*beans[i]);
        return res;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i]==nums[j] && (i*j)%k==0) res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3 != 0) return {};
        long long a = num/3-1;
        return {a, a+1, a+2};
    }
};

class Solution {
public:
    vector<long long> maximumEvenSplit(long long S) {
        if(S%2) return {};
        vector<long long> v(110000), res;
        for(long long i = 1; i < 110000; i++){
            v[i] = v[i-1]+i*2;
        }
        // cout << v.back() << endl;
        auto it = lower_bound(v.begin(), v.end(), S);
        if(*it > S) it--;
        long long p = 2, s = 0;
        for(auto i = v.begin(); i!=it; i++){
            res.push_back(p);
            s += p;
            p += 2;
        }
        res.pop_back();
        p -= 2;
        s -= p;
        // cout << s << " " << p << " " << S-s << endl;
        long long ad = S-s;
        if(ad < p) ad += res.back() , res.pop_back();
        res.push_back(ad);
        return res;
    }
};


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
        else res = n-max({a1+b2, b1+a2});
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

class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for(int i = 1; i <= num; i++){
            int tmp = i, s = 0;
            while(tmp) s += tmp%10, tmp /= 10;
            if(s%2 == 0) res++;
        }
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
    ListNode* mergeNodes(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode *now = head->next;
        while(now->next->val != 0){
            now->val += now->next->val;
            ListNode *tmp = now->next;
            now->next = tmp->next;
            delete tmp;
        }
        now->next = mergeNodes(now->next);
        return head->next;
    }
};

class Solution {
public:
    string repeatLimitedString(string s, int L) {
        map<char, int> m;
        for(auto c : s) m[c]++;
        int n = 0, cnt = 0;
        char pre = '0';
        string res = "";
        while(n < s.size()){
            auto it = m.rbegin();
            int k = min(L, it->second);
            if(it->first == pre){
                it++;
                if(it == m.rend()) break;
                k = 1;
            }
            m[it->first] -= k;
            pre = it->first, n += k;
            while(k--) res += it->first;
            if(m[it->first] == 0) m.erase(it->first);
        }
        return res;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(auto& s: words) if(s.substr(0, pref.size()) == pref) res++;
        return res;
    }
};

class Solution {
public:
    int minSteps(string s, string t) {
        int a[26] = {}, b[26] = {}, res = 0;
        for(auto c : s) a[c-'a']++;
        for(auto c : t) b[c-'a']++;
        for(int i = 0; i < 26; i++){
            res += abs(a[i]-b[i]);
        }
        return res;
    }
};

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, r = (1e14)+5;
        while(l < r){
            long long mid = (l+r)/2;
            long long now = 0;
            for(auto i : time) now += mid/i;
            if(now >= totalTrips) r = mid;
            else l = mid+1;
        }
        return l;
    }
};

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int res = 0, mm = -1;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == key) m[nums[i+1]]++;
            if(m[nums[i+1]] > mm) mm = m[nums[i+1]], res = nums[i+1];
        }
        return res;
    }
};

class Solution {
public:
    int Get(int n, vector<int>& m){
        if(n == 0) return m[0];
        int res = 0, p = 1;
        while(n){
            res += p*m[n%10];
            p *= 10, n /= 10;
        }
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int k = Get(nums[i], mapping);
            v[i] = {k, nums[i]};
        }
        stable_sort(v.begin(), v.end(), [](auto a, auto b){return a.first<b.first;});
        for(int i = 0; i < nums.size(); i++){
            nums[i] = v[i].second;
        }
        return nums;
    }
};

class Solution {
public:
    void dfs(int now, vector<unordered_set<int>>& r, unordered_set<int>& e, vector<int>& c, queue<int>& q){
        for(auto i : e){
            r[i].insert(now);
            for(auto j : r[now]) r[i].insert(j);
            if(--c[i] == 0) q.push(i);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> r(n), e(n);
        vector<int> c(n);
        for(auto& v : edges){
            e[v[0]].insert(v[1]);
            c[v[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) if(c[i] == 0) q.push(i);
        while(!q.empty()){
            int now = q.front(); q.pop();
            dfs(now, r, e[now], c, q);
        }
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++){
            for(auto j : r[i]) res[i].push_back(j);
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int res = 0;
        while(s != ""){
            int idx = s.find(s.back());
            if(idx == s.size()-1) res += idx/2;
            else res += idx, s.erase(idx, 1);
            s.pop_back();
        }
        return res;
    }
};

class Solution {
public:
    vector<string> cellsInRange(string s) {
        string ss = "XX";
        vector<string> res;
        for(char i = s[0]; i <= s[3]; i++){
            ss[0] = i;
            for(char j = s[1]; j <= s[4]; j++){
                ss[1] = j;
                res.push_back(ss);
            }
        }
        return res;
    }
};

class Solution {
public:
    long long minimalKSum(vector<int>& nums, long long k) {
        long long res = k*(k+1)/2, idx = k+1;
        set<int> s(nums.begin(), nums.end());
        for(auto i : s){
            if(i < idx) res += idx++, res -= i;
        }
        return res;
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> pa, ch;
        for(auto& i : descriptions){
            int p = i[0], c = i[1], l = i[2];
            TreeNode *a = nullptr, *b = nullptr;
            if(m.count(p)) a = m[p];
            else m[p] = a = new TreeNode(p);
            if(m.count(c)) b = m[c];
            else m[c] = b = new TreeNode(c);
            if(l == 1) a->left = b;
            else a->right = b;
            pa.insert(p), ch.insert(c);
        }
        for(auto i : pa){
            if(!ch.count(i)) return m[i];
        }
        return nullptr;
    }
};

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        nums.push_back(1);
        vector<int> res;
        int idx = 1, now = nums[0];
        while(idx < nums.size()){
            int a = gcd(now, nums[idx]);
            if(a > 1) now = (long long)now*nums[idx]/a, idx++;
            else{
                while(!res.empty()){
                    int k = gcd(now, res.back());
                    if(k > 1) now = (long long)now*res.back()/k, res.pop_back();
                    else break;
                }
                res.push_back(now);
                now = nums[idx];
                idx++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int prev = -1;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key){
                for(int j = max(prev+1, i-k); j < i; j++) res.push_back(j);
                prev = i+k;
            }
            if(i <= prev) res.push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int res = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(auto& i : dig) dp[i[0]+1][i[1]+1] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+dp[i][j];
            }
        }
        for(auto& i : artifacts){
            int k = dp[i[2]+1][i[3]+1]-dp[i[2]+1][i[1]]-dp[i[0]][i[3]+1]+dp[i[0]][i[1]];
            if(k == (i[2]-i[0]+1)*(i[3]-i[1]+1)) res++;
        }
        return res;
    }
};

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1 && k%2==1) return -1;
        if(k >= n){
            int r = k-n;
            if(r == 0) return *max_element(nums.begin(), nums.begin()+(n-1));
            else return *max_element(nums.begin(), nums.end());
        }
        else{
            if(k == 0) return nums[0];
            if(k == 1) return nums[k];
            int a = *max_element(nums.begin(), nums.begin()+(k-1));
            return max(a, nums[k]);
        }
        return -1;
    }
};

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto i : nums) m[i]++;
        for(auto& [i, v] : m){
            if(v%2) return false;
        }
        return true;
    }
};

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long c1 = 0, c2 = 0, res = 0;
        for(auto c : text){
            if(c == pattern[1]) res += c1, c2++;
            if(c == pattern[0]) c1++;
        }
        res += max(c1, c2);
        return res;
    }
};

class Solution {
public:
    int halveArray(vector<int>& nums) {
        double total = 0;
        for(auto i : nums) total += i;
        double now = total;
        multiset<double> s(nums.begin(), nums.end());
        int res = 0;
        while(now > total/2){
            auto it  = s.rbegin();
            double ne = (*it)/2;
            now -= (*it);
            now += ne;
            s.erase(s.find(*it));
            s.insert(ne);
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i <= nums.size()-2; i++){
            if(nums[i+1] == nums[i]) {nums.erase(nums.begin()+(i+1)); i--; continue;}
            if(nums[i-1]<nums[i] && nums[i+1]<nums[i]) res++;
            if(nums[i-1]>nums[i] && nums[i+1]>nums[i]) res++;
        }
        return res;
    }
};


class Solution {
public:
    int countCollisions(string d) {
        int n = d.size(), res = n;
        for(int i = 0; i < n; i++){
            if(d[i] == 'L') res--;
            else break;
        }
        for(int i = n-1; i >= 0; i--){
            if(d[i] == 'R') res--;
            else break;
        }
        for(auto c : d) if(c == 'S') res--;
        return res;
    }
};

class Solution {
public:
    vector<int> maximumBobPoints(int num, vector<int>& A) {
        int M = 0, res = 0;
        for(int i = 0; i < (1<<12); i++){
            int total = 0, t = 0, m = 0;
            for(int j = 0; j < 12; j++){
                if((i>>j)&1){
                    t |= (1<<j);
                    total += (A[j]+1);
                    m += j;
                }
            }
            if(total<=num && m>M){
                M = m, res = t;
            }
        }
        int to = 0;
        vector<int> v(12);
        for(int i = 0; i < 12; i++){
            if((res>>i)&1){
                v[i] = A[i]+1;
                to += v[i];
            }
        }
        if(to < num){
            int idx = 0;
            while(idx<12 && v[idx]==0) idx++;
            if(idx == 12) idx--;
            v[idx] += (num-to);
        }
        return v;
    }
};

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m1(nums1.begin(), nums1.end()), m2(nums2.begin(), nums2.end());
        vector<vector<int>> res(2);
        for(auto i : m1) if(!m2.count(i)) res[0].push_back(i);
        for(auto i : m2) if(!m1.count(i)) res[1].push_back(i);
        return res;
    }
};

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int flip = 0, res = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if((i%2==0&&!flip) || (i%2==1&&flip)){
                if(nums[i] == nums[i+1]) res++, flip ^= 1;
            }
        }
        if((nums.size()-res)%2) res++;
        return res;
    }
};

class Solution {
public:
    string getS(int idx, int L, vector<long long>& dp){
        if(L == 0) return "";
        else if(L == 1) return to_string(idx);
        else if(L == 2) return to_string(idx)+to_string(idx);
        int i = idx/dp[L-2], j = idx%dp[L-2];
        return to_string(i)+getS(j, L-2, dp)+to_string(i);
    }
    vector<long long> kthPalindrome(vector<int>& queries, int L) {
        vector<long long> dp(16), res;
        dp[0] = 0, dp[1] = 10, dp[2] = 10;
        for(int i = 3; i < dp.size(); i++) dp[i] = 10*dp[i-2];
        long long n;
        if(L == 1) n = 10;
        else if(L == 2) n = 9;
        else n = 9*dp[L-2];
        for(auto i : queries){
            if(L == 1) res.push_back(i<=9?i:-1);
            else if(L == 2) res.push_back(i<=9?i*10+i:-1);
            else if(i > n) res.push_back(-1);
            else{
                int j = (i-1)/dp[L-2]+1, k = (i-1)%dp[L-2];
                string now = getS(k, L-2, dp);
                long long r = j;
                for(auto c : now) r = r*10+(c-'0');
                r = r*10+j;
                res.push_back(r);
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(k+1, vector<int>(n+1));
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                int nc = piles[j-1].size(), s = 0;
                dp[i][j] = dp[i][j-1];
                for(int c = 1; c<=i && c<=nc; c++){
                    s += piles[j-1][c-1];
                    dp[i][j] = max(dp[i][j], dp[i-c][j-1]+s);
                }
            }
        }
        return dp[k][n];
    }
};

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        while(start || goal){
            if((start&1) != (goal&1)) res++;
            start >>= 1, goal >>= 1;
        }
        return res;
    }
};

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = n; i > 1; i--){
            for(int j = 0; j < i-1; j++){
                nums[j] = (nums[j]+nums[j+1])%10;
            }
        }
        return nums[0];
    }
};

class Solution {
public:
    long long numberOfWays(string s) {
        vector<long long> dp(1, 0);
        char prev = s[0];
        for(auto c : s){
            if(c == prev) dp.back()++;
            else dp.push_back(1), prev = c;
        }
        if(dp.size() < 3) return 0;
        long long res = 0, _0 = dp[0], _1 = dp[1], _01 = dp[0]*dp[1], _10 = 0;
        for(int i = 2; i < dp.size(); i++){
            if(i%2 == 0){
                res += _01*dp[i];
                _10 += _1*dp[i];
                _0 += dp[i];
            }
            else{
                res += _10*dp[i];
                _01 += _0*dp[i];
                _1 += dp[i];
            }
        }
        return res;
    }
};

class Solution {
public:
    int convertTime(string current, string correct) {
        auto getNum = [] (string& s, int l, int r){
            int res = 0;
            for(int i = l; i <= r; i++) res = 10*res+(s[i]-'0');
            return res;
        };
        int h1 = getNum(current, 0, 1), m1 = getNum(current, 3, 4);
        int h2 = getNum(correct, 0, 1), m2 = getNum(correct, 3, 4);
        if(m1 > m2) m2 += 60, h2--;
        if(h1 > h2) h2 += 24;
        int res = 0, total = (m2-m1)+60*(h2-h1);
        res += total/60, total %= 60;
        res += total/15, total %= 15;
        res += total/5, total %= 5;
        res += total;
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        for(auto& i : matches){
            m[i[0]] = m[i[0]];
            m[i[1]]++;
        }
        vector<vector<int>> res(2);
        for(auto& [key, val] : m){
            if(val == 0) res[0].push_back(key);
            if(val == 1) res[1].push_back(key);
        }
        return res;
    }
};

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = accumulate(candies.begin(), candies.end(), (long long)0);
        if(total < k) return 0;
        auto valid = [&](long long num){
            long long res = 0;
            for(auto i : candies) res += i/num;
            return res>=k;
        };
        long long l = 1, r = total/k;
        while(l < r){
            long long mid = l+(r-l)/2+1;
            if(valid(mid)) l = mid;
            else r = mid-1;
        }
        return l;
    }
};

class Solution {
public:
    int largestInteger(int num) {
        vector<int> v1, v2, k;
        int res = 0;
        while(num){
            if(num%2) v1.push_back(num%10), k.push_back(1);
            else v2.push_back(num%10), k.push_back(2);
            num /= 10;
        }
        int id1 = v1.size()-1, id2 = v2.size()-1;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i = k.size()-1; i >= 0; i--){
            if(k[i] == 1) res = 10*res+v1[id1--];
            else res = 10*res+v2[id2--];
        }
        return res;
    }
};

class Solution {
public:
    string minimizeResult(string e) {
        int M = INT_MAX, id = e.find('+');
        string res, s1 = e.substr(0, id), s2 = e.substr(id+1);
        for(int i = 0; i < s1.size(); i++){
            for(int j = 0; j < s2.size(); j++){
                int n1 = i==0?1:stoi(s1.substr(0, i));
                int n2 = stoi(s1.substr(i))+stoi(s2.substr(0, j+1));
                int n3 = j==s2.size()-1?1:stoi(s2.substr(j+1));
                if(M > n1*n2*n3){
                    M = n1*n2*n3;
                    res = s1.substr(0, i)+"("+s1.substr(i)+"+"+s2.substr(0, j+1)+")"+s2.substr(j+1);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    const int mod = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());
        while(k--){
            int now = q.top(); q.pop();
            q.push(now+1);
        }
        long long res = 1;
        while(!q.empty()){
            res = (res*q.top())%mod;
            q.pop();
        }
        return res;
    }
};

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = 0, m = INT_MAX;
        for(auto i : nums){
            int k = abs(i);
            if(k < m) res = i, m = k;
            else if(k == m && i > res) res = i;
        }
        return res;
    }
};

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res = 0;
        for(int i = 0; i*cost1 <= total; i++){
            int now = total-i*cost1;
            res += now/cost2+1;
        }
        return res;
    }
};

class ATM {
private:
    vector<long long> v;
    int m[5];
public:
    ATM() {
        v = vector<long long>(5, 0);
        m[0] = 20, m[1] = 50, m[2] = 100, m[3] = 200, m[4] = 500;
    }
    
    void deposit(vector<int> bC) {
        for(int i = 0; i < 5; i++){
            v[i] += bC[i];
        }
    }
    
    vector<int> withdraw(long long amount) {
        vector<int> res(5, 0);
        for(int i = 4; i >= 0; i--){
            int k = min(amount/m[i], v[i]);
            res[i] += k;
            amount -= m[i]*k;
        }
        if(amount != 0) return {-1};
        for(int i = 4; i >= 0; i--) v[i] -= res[i];
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */

class Solution {
public:
    struct S{int t, a, b;};
    bool diff(S& a, S& b){
        if(a.a==b.a || a.a==b.b) return false;
        if(a.b==b.a || a.b==b.b) return false;
        return true;
    }
    bool connect(S& a, S& b, vector<unordered_set<int>>& g){
        if(g[a.a].count(b.a)) return true;
        if(g[a.a].count(b.b)) return true;
        if(g[a.b].count(b.a)) return true;
        if(g[a.b].count(b.b)) return true;
        return false;
    }
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size(), m = edges.size(), res = -1;
        vector<unordered_set<int>> graph(n);
        for(auto& i : edges){
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        vector<S> v(m), used;
        for(int i = 0; i < m; i++){
            v[i].a = edges[i][0], v[i].b = edges[i][1];
            v[i].t = scores[edges[i][0]]+scores[edges[i][1]];
        }
        sort(v.begin(), v.end(), [](auto a, auto b){return a.t > b.t;});
        for(int i = 0; i < m; i++){
            if(!used.empty() && v[i].t+used[0].t <= res) break;
            for(int j = 0; j < used.size(); j++){
                if(v[i].t+used[j].t <= res) break;
                if(!diff(v[i], used[j])) continue;
                if(connect(v[i], used[j], graph)) res = max(res, v[i].t+used[j].t);
            }
            used.push_back(v[i]);
        }
        return res;
    }
};

class Solution {
public:
    string digitSum(string s, int k) {
        string tmp;
        while(s.size() > k){
            string tmp = "";
            for(int i = 0; i < (s.size()%k?s.size()/k+1:s.size()/k); i++){
                int now = 0;
                for(int j = i*k; j < min((int)s.size(), i*k+k); j++) now += (s[j]-'0');
                tmp += to_string(now);
            }
            s = tmp;
        }
        return s;
    }
};

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int res = 0;
        unordered_map<int, int> m;
        for(auto i : tasks) m[i]++;
        for(auto& [i, v] : m){
            if(v == 1) return -1;
            else if(v == 2 || v == 3) res += 1;
            else if(v == 4) res += 2;
            else if(v%3 == 1) res += (v/3-1+2);
            else res +=(v/3+v%3/2);
        }
        return res;
    }
};

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<pair<int, int>>> r(m+1, vector<pair<int, int>>(n+1)), c(n+1, vector<pair<int, int>>(m+1));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int p = 0, q = 0;
                while(grid[i-1][j-1]%2 == 0) p++, grid[i-1][j-1] /= 2;
                while(grid[i-1][j-1]%5 == 0) q++, grid[i-1][j-1] /= 5;
                r[i][j].first = r[i][j-1].first+p;
                c[j][i].first = c[j][i-1].first+p;
                r[i][j].second = r[i][j-1].second+q;
                c[j][i].second = c[j][i-1].second+q;
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                auto [v11, v12] = c[j][i];
                int v21 = c[j][m].first-c[j][i-1].first, v22 = c[j][m].second-c[j][i-1].second;
                auto [h11, h12] = r[i][j-1];
                int h21 = r[i][n].first-r[i][j].first, h22 = r[i][n].second-r[i][j].second;
                res = max(res, min(v11+h11, v12+h12));
                res = max(res, min(v11+h21, v12+h22));
                res = max(res, min(v21+h11, v22+h12));
                res = max(res, min(v21+h21, v22+h22));
            }
        }       
        return res;
    }
};

class Solution {
public:
    string removeDigit(string number, char digit) {
        string res = "0";
        for(int i = 0; i < number.size(); i++){
            if(number[i] != digit) continue;
            string tmp = number.substr(0,i)+number.substr(i+1, number.size()-i-1);
            res = max(res, tmp);
        }
        return res;
    }
};

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res = -1;
        unordered_map<int, int> m;
        for(int i = 0; i < cards.size(); i++){
            if(m.count(cards[i])){
                 if(res==-1 || i-m[cards[i]]+1<res) res = i-m[cards[i]]+1;
            }
            m[cards[i]] = i;
        }
        return res;
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size(), res = 0;
        vector<set<vector<int>>> s(n);
        for(int i = 0; i < n; i++){
            int cnt = 0;
            vector<int> tmp;
            for(int j = i; j < n; j++){
                if(cnt == k && nums[j]%p == 0) break;
                if(nums[j]%p == 0) cnt++;
                tmp.push_back(nums[j]);
                if(!s[j-i].count(tmp)) res++;
                s[j-i].insert(tmp);
            }
        }
        return res;
    }
};

class Solution {
public:
    long long appealSum(string s) {
        long long res = 0, prev = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            int tmp = m.count(s[i])?(i-m[s[i]]):(i+1);
            res += prev+tmp;
            prev += tmp;
            m[s[i]] = i;
        }
        return res;
    }
};

class Solution {
public:
    string largestGoodInteger(string s) {
        string res = "";
        for(int i = 2; i < s.size(); i++){
            if(s[i]==s[i-1] && s[i]==s[i-2]) res = max(res, s.substr(i-2, 3));
        }
        return res;
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
    pair<int, int> dfs(TreeNode *root, int &res){
        if(!root) return {0, 0};
        auto a = dfs(root->left, res);
        auto b = dfs(root->right, res);
        int aver = (root->val+a.second+b.second)/(a.first+b.first+1);
        res += (aver==root->val);
        return {a.first+b.first+1, root->val+a.second+b.second};
    }
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};

class Solution {
public:
    int countTexts(string s) {
        s += "#";
        const int mod = 1e9+7;
        long long res = 1;
        unordered_map<char, int> m{{'2',3},{'3',3},{'4',3},{'5',3},{'6',3},{'7',4},{'8',3},{'9',4}};
        int cnt = 1;
        vector<long long> dp(2, 1);
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                cnt++;
                dp.push_back(0);
                for(int j = 1; j <= m[s[i]]; j++){
                    if(cnt-j < 0) break;
                    dp[cnt] = (dp[cnt]+dp[cnt-j])%mod;
                }
            }
            else{
                cnt = 1;
                res = (res*dp.back())%mod;
                dp = vector<long long>(2, 1);
            }
        }
        return res;
    }
};

class Solution {
public:
    int m, n, step, mem[105][105][105] = {};
    bool dfs(int x, int y, int d, vector<vector<char>>& A){
        d += A[x][y]=='('?1:-1;
        if(d<0 || d>(step)-(x+y+1) || mem[x][y][d]) return false;
        mem[x][y][d] = true;
        if(x==m-1 && y==n-1) return d==0;
        if(x<m-1 && dfs(x+1, y, d, A)) return true;
        if(y<n-1 && dfs(x, y+1, d, A)) return true;
        return false;
    }
    bool hasValidPath(vector<vector<char>>& A) {
        m = A.size(), n = A[0].size(), step = m+n-1;
        if(A[0][0]==')' || A[m-1][n-1]=='(' || step%2) return false;
        return dfs(0, 0, 0, A);
    }
};

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int res = 0;
        string s = to_string(num);
        for(int i = 0; i < s.size()-k+1; i++){
            string now = s.substr(i, k);
            int d = stoi(now);
            if(d == 0) continue;
            if(num%d == 0) res++;
        }
        return res;
    }
};

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++) dp[i] = dp[i-1]+nums[i];
        int res = 0;
        for(int i = 0; i < n-1; i++){
            long long a = dp[i];
            long long b = dp[n-1]-dp[i];
            if(a >= b) res++;
        }
        return res;
    }
};

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& A, int L) {
        int n = A.size();
        sort(A.begin(), A.end());
        vector<int> s(n);
        for(int i = 0; i < n; i++) s[i] = A[i][0];
        vector<long long> dp(n);
        dp[0] = A[0][1]-A[0][0]+1;
        for(int i = 1; i < n; i++) dp[i] = dp[i-1]+A[i][1]-A[i][0]+1;
        int res = 0;
        for(int i = 0; i < n; i++){
            int M = A[i][0]+L;
            auto it = lower_bound(s.begin(), s.end(), M);
            int idx = it-s.begin();
            idx--;
            int now ;
            if(A[idx][1] < M) now = dp[idx]-(i==0?0:dp[i-1]);
            else now = (idx==0?0:dp[idx-1])-(i==0?0:dp[i-1])+M-A[idx][0];
            res = max(res, now);
        }
        return res;
    }
};

#define INF 0x3f3f3f3f
class Solution {
public:
    int solve(string& s, char c1, char c2){
        int res = 0, now = 0, mn = INF, last = INF, t = 0;
        for(auto c : s){
            if(c!=c1 && c!=c2) continue;
            if(c == c1) now--;
            if(c == c2) now++, t++;
            if(now != t) res = max(res, now);
            res = max(res, now-mn);
            mn = min(mn, last);
            last = now;
        }
        if(res == t) res--;
        return res;
    }
    int largestVariance(string s) {
        int res = 0;
        vector<bool> v(26);
        for(auto c : s) v[c-'a'] = true;
        for(char c1 = 'a'; c1 <= 'z'; c1++){
            if(!v[c1-'a']) continue;
            for(char c2 = 'a'; c2 <= 'z'; c2++){
                if(c1 == c2 || !v[c2-'a']) continue;
                res = max(res, solve(s, c1, c2));
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        for(int i = 1; i < words.size(); i++){
            int a[26] = {}, b[26] = {};
            for(auto c : words[i]) a[c-'a']++;
            for(auto c : res.back()) b[c-'a']++;
            for(int j = 0; j < 26; j++) {if(a[j] != b[j]) {res.push_back(words[i]); break;}}
        }
        return res;
    }
};

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int res = max(special[0]-bottom, top-special.back());
        for(int i = 1; i < special.size(); i++){
            res = max(res, special[i]-special[i-1]-1);
        }
        return res;
    }
};

class Solution {
public:
    int largestCombination(vector<int>& A) {
        vector<int> v(32);
        for(auto i : A){
            bitset<32> b(i);
            for(int j = 0; j < 32; j++) v[j] += b[j];
        }
        return *max_element(v.begin(), v.end());
    }
};

#define P pair<int, int>
#define F first
#define S second
class CountIntervals {
public:
    map<int, int> m;
    int cnt = 0;
    CountIntervals() {}
    
    void add(int l, int r) {
        int s = l, e = r;
        auto it = m.lower_bound(l);
        while(it!=m.end() && it->S<=r+1){
            s = min(s, it->S);
            e = max(e, it->F);
            cnt -= it->F-it->S+1;
            it = m.erase(it);
        }
        m[e] = s;
        cnt += e-s+1;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

class Solution {
public:
    bool digitCount(string num) {
        int a[10] = {};
        for(auto c : num) a[c-'0']++;
        for(int i = 0; i < num.size(); i++){
            if(a[i] != num[i]-'0') return false;
        }
        return true;
    }
};

class Solution {
public:
    int getWords(string& s){
        int res = 1;
        for(auto c :s) if(c == ' ') res++;
        return res;
    }
    string largestWordCount(vector<string>& m, vector<string>& s) {
        unordered_map<string, int> um;
        int n = m.size();
        for(int i = 0; i < n; i++){
            int num = getWords(m[i]);
            um[s[i]] += num;
        }
        string res = "";
        int N = -1;
        for(auto& [u, v]: um){
            if(v > N) res = u, N = v;
            else if(v == N && u > res) res = u;
        }
        return res;
    }
};

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& A) {
        vector<int> cnt(n);
        for(auto& i : A) cnt[i[0]]++, cnt[i[1]]++;
        sort(cnt.begin(), cnt.end());
        long long res = 0;
        for(int i = 0; i < n; i++){
            res += cnt[i]*(long long)(i+1);
        }
        return res;
    }
};

class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        int a[26] = {}, b[26] = {}, res = INT_MAX;
        for(auto c : s) a[c-'a']++;
        for(auto c : t) b[c-'a']++;
        for(int i = 0; i < 26; i++) if(b[i]!=0) res = min(res, a[i]/b[i]);
        return res;
    }
};


#define P pair<int, int>
#define F first
#define S second
class Solution {
public:
    int totalSteps(vector<int>& A) {
        int res = 0, n = A.size();
        stack<P> s;
        s.push({A[n-1], 0});
        for(int i = n-2; i >= 0; i--){
            int cnt = 0;
            while(!s.empty() && s.top().F<A[i]){
                cnt = max(cnt+1, s.top().S);
                s.pop();
            }
            s.push({A[i], cnt});
            res = max(res, cnt);
        }
        return res;
    }
};

#define P pair<int, int>
#define F first
#define S second
class Solution {
private:
    struct cmp{
        bool operator()(P a, P b){
            return a.F > b.F;
        }  
    };
public:
    int minimumObstacles(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        const int DIR[5] = {-1, 0, 1, 0, -1};
        vector<int> dist(m*n, INT_MAX);
        priority_queue<P, vector<P>, cmp> q;
        q.push({A[0][0], 0});
        dist[0] = A[0][0];
        while(!q.empty()){
            auto [d, idx] = q.top(); q.pop();
            if(idx == m*n-1) return d;
            int x = idx/n, y = idx%n;
            for(int i = 0; i < 4; i++){
                int nx = x+DIR[i], ny = y+DIR[i+1];
                if(nx<0||nx>=m||ny<0||ny>=n||dist[nx*n+ny]<=d+A[nx][ny]) continue;
                dist[nx*n+ny] = d+A[nx][ny];
                q.push({d+A[nx][ny], nx*n+ny});
            }
        }
        return dist[m*n-1];
    }
};

class Solution {
public:
    int minMaxGame(vector<int>& A) {
        if(A.size() == 1) return A[0];
        vector<int> B;
        bool flag = true;
        for(int i = 0; i < A.size(); i += 2){
            if(flag) B.push_back(min(A[i], A[i+1]));
            else B.push_back(max(A[i], A[i+1]));
            flag = !flag;
        }
        return minMaxGame(B);
    }
};

class Solution {
public:
    int partitionArray(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int res = 1, m = A[0];
        for(int i = 1; i < A.size(); i++){
            if(A[i]-m > k){
                m = A[i];
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> arrayChange(vector<int>& A, vector<vector<int>>& O) {
        unordered_map<int, int> m1, m2;
        for(auto& i : O){
            int x = i[0], y = i[1];
            if(m2.count(x)){
                int tmp = m2[x];
                m1[tmp] = y;
                m2[y] = tmp;
                if(x != tmp) m2.erase(x);
            }
            else m1[x] = y, m2[y] = x;
        }
        for(auto& i : A) i = m1.count(i)?m1[i]:i;
        return A;
    }
};

class TextEditor {
private:
    struct Node{
        char c;
        Node *prev, *next;
        Node(){}
        Node(char c, Node *prev, Node *next):c(c),prev(prev),next(next){}
    };
    Node *head, *cursor;
    string getStr() const {
        string res = "";
        int t = 10;
        Node *tmp = cursor;
        while(t--){
            if(tmp == head) break;
            res += tmp->c;
            tmp = tmp->prev;
        }
        reverse(res.begin(), res.end());
        return res;
    }
public:
    TextEditor() {
        cursor = head = new Node('#', nullptr, nullptr);
    }
    
    void addText(string text) {
        for(auto i : text){
            Node *newNode = new Node(i, cursor, cursor->next);
            if(cursor->next) cursor->next->prev = newNode;
            cursor->next = newNode;
            cursor = newNode;
        }
    }
    
    int deleteText(int k) {
        int res = 0;
        while(k--){
            if(cursor == head) break;
            if(cursor->next) cursor->next->prev = cursor->prev;
            if(cursor->prev) cursor->prev->next = cursor->next;
            Node *tmp = cursor;
            cursor = cursor->prev;
            delete tmp;
            res++;
        }
        return res;
    }
    
    string cursorLeft(int k) {
        while(k--){
            if(cursor == head) break;
            cursor = cursor->prev;
        }
        return getStr();
    }
    
    string cursorRight(int k) {
        while(k--){
            if(!cursor->next) break;
            cursor = cursor->next;
        }
        return getStr();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        if(s.size() < 8) return false;
        bool flag = false;
        for(auto c : s) if(c>='a' && c<='z') flag = true;
        if(!flag) return false;
        flag = false;
        for(auto c : s) if(c>='A' && c<='Z') flag = true;
        if(!flag) return false;
        flag = false;
        for(auto c : s) if(c>='0' && c<='9') flag = true;
        if(!flag) return false;
        flag = false;
        unordered_set<char> us{'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        for(auto c : s) if(us.count(c)) flag = true;
        if(!flag) return false;
        for(int i = 1; i < s.size(); i++) if(s[i] == s[i-1]) return false;
        return true;
    }
};

class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        sort(p.begin(), p.end());
        for(auto& i : s){
            long long k = success%i?success/i+1:success/i;
            auto it = lower_bound(p.begin(), p.end(), k);
            i = p.size()-(it-p.begin());
        }
        return s;
    }
};

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size(), m = sub.size();
        unordered_map<char, unordered_set<char>> um;
        for(auto& i : mappings){
            um[i[0]].insert(i[1]);
        }
        for(int i = 0; i < n-m+1; i++){
            string now = s.substr(i, m);
            bool flag = true;
            for(int j = 0; j < m; j++){
                if(sub[j]!=now[j] && !um[sub[j]].count(now[j])){
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& A, long long k) {
        long long res = 0, sum = 0, l = 0, score;
        for(int i = 0; i < A.size(); i++){
            sum += A[i];
            while(sum*(i-l+1) >= k && l <= i) sum -= A[l], l++;
            if(l <= i) res += (i-l+1);
        }
        return res;
    }
};

class Solution {
public:
    int countAsterisks(string s) {
        int res = 0, state = 1;
        for(auto c : s){
            if(c == '|') state = !state;
            else if(state && c == '*') res++; 
        }
        return res;
    }
};

class Solution {
private:
    int dfs(int idx, vector<bool>& used, vector<vector<int>>& graph){
        int res = 1;
        used[idx] = true;
        for(auto i : graph[idx]){
            if(used[i]) continue;
            res += dfs(i, used, graph);
        }
        return res;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res = 0;
        vector<vector<int>> graph(n);
        for(auto& i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<bool> used(n);
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            int k = dfs(i, used, graph);
            res += (long long)k*(n-k);
        }
        return res/2;
    }
};

class Solution {
public:
    int maximumXOR(vector<int>& A) {
        int res = 0;
        for(auto i : A) res |= i;
        return res;
    }
};

class Solution {
public:
    int distinctSequences(int n) {
        if(n == 1) return 6;
        long long dp[10005][7][7] = {}, mod = 1e9+7;
        dp[2][1][1] = 0, dp[2][1][2] = 1, dp[2][1][3] = 1, dp[2][1][4] = 1, dp[2][1][5] = 1, dp[2][1][6] = 1;
        dp[2][2][1] = 1, dp[2][2][2] = 0, dp[2][2][3] = 1, dp[2][2][4] = 0, dp[2][2][5] = 1, dp[2][2][6] = 0;
        dp[2][3][1] = 1, dp[2][3][2] = 1, dp[2][3][3] = 0, dp[2][3][4] = 1, dp[2][3][5] = 1, dp[2][3][6] = 0;
        dp[2][4][1] = 1, dp[2][4][2] = 0, dp[2][4][3] = 1, dp[2][4][4] = 0, dp[2][4][5] = 1, dp[2][4][6] = 0;
        dp[2][5][1] = 1, dp[2][5][2] = 1, dp[2][5][3] = 1, dp[2][5][4] = 1, dp[2][5][5] = 0, dp[2][5][6] = 1;
        dp[2][6][1] = 1, dp[2][6][2] = 0, dp[2][6][3] = 0, dp[2][6][4] = 0, dp[2][6][5] = 1, dp[2][6][6] = 0;
        for(int i = 3; i <= n; i++){
            dp[i][1][2] = (dp[i-1][1][1]+dp[i-1][3][1]+dp[i-1][4][1]+dp[i-1][5][1]+dp[i-1][6][1])%mod;
            dp[i][1][3] = (dp[i-1][1][1]+dp[i-1][2][1]+dp[i-1][4][1]+dp[i-1][5][1]+dp[i-1][6][1])%mod;
            dp[i][1][4] = (dp[i-1][1][1]+dp[i-1][2][1]+dp[i-1][3][1]+dp[i-1][5][1]+dp[i-1][6][1])%mod;
            dp[i][1][5] = (dp[i-1][1][1]+dp[i-1][2][1]+dp[i-1][3][1]+dp[i-1][4][1]+dp[i-1][6][1])%mod;
            dp[i][1][6] = (dp[i-1][1][1]+dp[i-1][2][1]+dp[i-1][3][1]+dp[i-1][4][1]+dp[i-1][5][1])%mod;
            
            dp[i][2][1] = (dp[i-1][2][2]+dp[i-1][3][2]+dp[i-1][4][2]+dp[i-1][5][2]+dp[i-1][6][2])%mod;
            dp[i][2][3] = (dp[i-1][1][2]+dp[i-1][2][2]+dp[i-1][4][2]+dp[i-1][5][2]+dp[i-1][6][2])%mod;
            dp[i][2][5] = (dp[i-1][1][2]+dp[i-1][2][2]+dp[i-1][3][2]+dp[i-1][4][2]+dp[i-1][6][2])%mod;
            
            dp[i][3][1] = (dp[i-1][2][3]+dp[i-1][3][3]+dp[i-1][4][3]+dp[i-1][5][3]+dp[i-1][6][3])%mod;
            dp[i][3][2] = (dp[i-1][1][3]+dp[i-1][3][3]+dp[i-1][4][3]+dp[i-1][5][3]+dp[i-1][6][3])%mod;
            dp[i][3][4] = (dp[i-1][1][3]+dp[i-1][2][3]+dp[i-1][3][3]+dp[i-1][5][3]+dp[i-1][6][3])%mod;
            dp[i][3][5] = (dp[i-1][1][3]+dp[i-1][2][3]+dp[i-1][3][3]+dp[i-1][4][3]+dp[i-1][6][3])%mod;
                
            dp[i][4][1] = (dp[i-1][2][4]+dp[i-1][3][4]+dp[i-1][4][4]+dp[i-1][5][4]+dp[i-1][6][4])%mod;
            dp[i][4][3] = (dp[i-1][1][4]+dp[i-1][2][4]+dp[i-1][4][4]+dp[i-1][5][4]+dp[i-1][6][4])%mod;
            dp[i][4][5] = (dp[i-1][1][4]+dp[i-1][2][4]+dp[i-1][3][4]+dp[i-1][4][4]+dp[i-1][6][4])%mod;
            
            dp[i][5][1] = (dp[i-1][2][5]+dp[i-1][3][5]+dp[i-1][4][5]+dp[i-1][5][5]+dp[i-1][6][5])%mod;
            dp[i][5][2] = (dp[i-1][1][5]+dp[i-1][3][5]+dp[i-1][4][5]+dp[i-1][5][5]+dp[i-1][6][5])%mod;
            dp[i][5][3] = (dp[i-1][1][5]+dp[i-1][2][5]+dp[i-1][4][5]+dp[i-1][5][5]+dp[i-1][6][5])%mod;
            dp[i][5][4] = (dp[i-1][1][5]+dp[i-1][2][5]+dp[i-1][3][5]+dp[i-1][5][5]+dp[i-1][6][5])%mod;
            dp[i][5][6] = (dp[i-1][1][5]+dp[i-1][2][5]+dp[i-1][3][5]+dp[i-1][4][5]+dp[i-1][5][5])%mod;
            
            dp[i][6][1] = (dp[i-1][2][6]+dp[i-1][3][6]+dp[i-1][4][6]+dp[i-1][5][6]+dp[i-1][6][6])%mod;
            dp[i][6][5] = (dp[i-1][1][6]+dp[i-1][2][6]+dp[i-1][3][6]+dp[i-1][4][6]+dp[i-1][6][6])%mod;
        }
        long long res = 0;
        for(int i = 1; i <= 6; i++){
            for(int j = 1; j <= 6; j++){
                res = (res+dp[n][i][j])%mod;
            }
        }
        return res;
    }
};

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& A) {
        int n = A.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i-j==0 || i+j==n-1){
                    if(A[i][j] == 0) return false;
                }
                else{
                    if(A[i][j] != 0) return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    int countHousePlacements(int n) {
        long long res = 0, mod = 1e9+7;
        vector<vector<long long>> dp(n+1, vector<long long>(4));
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
        for(int i = 2; i <= n; i++){
            dp[i][0] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
            dp[i][1] = (dp[i-1][0]+dp[i-1][2])%mod;
            dp[i][2] = (dp[i-1][0]+dp[i-1][1])%mod;
            dp[i][3] = dp[i-1][0];
        }
        for(auto i : dp[n]){
            res = (res+i)%mod;
        }
        return res;
    }
};

class Solution {
public:
    int maximumsSplicedArray(vector<int>& A1, vector<int>& A2) {
        int s1 = accumulate(A1.begin(), A1.end(), 0);
        int s2 = accumulate(A2.begin(), A2.end(), 0);
        int res = max(s1, s2), j = 0, n = A1.size();
        int p1 = 0, p2 = 0;
        for(int i = 0; i < n; i++){
            if(p1-p2 < 0) p1 = p2 = 0;
            p1 += A1[i], p2 += A2[i];
            res = max(res, s2-p2+p1);
        }
        j = p1 = p2 = 0;
        for(int i = 0; i < n; i++){
            if(p2-p1 < 0) p1 = p2 = 0;
            p1 += A1[i], p2 += A2[i];
            res = max(res, s1-p1+p2);
        }
        return res;
    }
};

class Solution {
private:
    void dfs(int idx, vector<int>& A, vector<vector<int>>& graph, vector<unordered_set<int>>& child){
        child[idx].insert(idx);
        for(auto i : graph[idx]){
            if(!child[i].empty()) continue;
            dfs(i, A, graph, child);
            A[idx] ^= A[i];
            for(auto j : child[i]) child[idx].insert(j);
        }
    }
public:
    int minimumScore(vector<int>& A, vector<vector<int>>& edges) {
        int n = A.size(), res = INT_MAX;
        vector<vector<int>> graph(n);
        for(auto& i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<unordered_set<int>> child(n);
        dfs(0, A, graph, child);
        for(int i = 1; i < n; i++){
            for(int j = i+1; j < n; j++){
                int s[3];
                if(child[i].count(j)){
                    s[0] = A[i]^A[j];
                    s[1] = A[j];
                    s[2] = A[0]^A[i];
                }
                else if(child[j].count(i)){
                    s[0] = A[i];
                    s[1] = A[i]^A[j];
                    s[2] = A[0]^A[j];
                }
                else{
                    s[0] = A[i];
                    s[1] = A[j];
                    s[2] = A[0]^A[i]^A[j];
                }
                sort(s, s+3);
                res = min(res, s[2]-s[0]);
            }
        }
        return res;
    }
};

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> m;
        int cnt = 0;
        for(auto c : key){
            if(c!=' ' && !m.count(c)) m[c] = 'a'+cnt++;
            if(cnt == 26) break;
        }
        string res = "";
        for(auto c : message){
            if(c == ' ') res += ' ';
            else res += m[c];
        }
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int state = 0, cnt = m*n, x = 0, y = 0;
        while(head && cnt){
            res[y][x] = head->val;
            head = head->next;
            if(state==0 && (x==n-1 || res[y][x+1]!=-1)) state++;
            else if(state==1 && (y==m-1 || res[y+1][x]!=-1)) state++;
            else if(state==2 && (x==0 || res[y][x-1]!=-1)) state++;
            else if(state==3 && (y==0 || res[y-1][x]!=-1)) state = 0;
            if(state == 0) x++;
            else if(state == 1) y++;
            else if(state == 2) x--;
            else if(state == 3) y--;
            cnt--;
        }
        return res;
    }
};

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long MOD = 1e9+7, res = 0;
        vector<vector<long long>> dp(n+1, vector<long long>(forget));
        dp[1][0] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < forget; j++)
                dp[i][j] = dp[i-1][j-1];
            for(int j = delay-1; j < forget-1; j++)
                dp[i][0] = (dp[i][0]+dp[i-1][j])%MOD;
        }
        for(int i = 0; i < forget; i++)
            res = (res+dp[n][i])%MOD;
        return res;
    }
};

class Solution {
private:
    int m, n, d[5] = {-1, 0, 1, 0, -1}, MOD = 1e9+7;
    long long dfs(int x, int y, vector<vector<long long>>& dp, vector<vector<int>>& A){
        long long res = 0;
        for(int i = 0; i < 4; i++){
            int nx = x+d[i], ny = y+d[i+1];
            if(nx<0||nx>=m||ny<0||ny>=n||A[nx][ny]<=A[x][y]) continue;
            res = (res+(1+(dp[nx][ny]?:dfs(nx, ny, dp, A))))%MOD;
        }
        return dp[x][y] = res;
    }
public:
    int countPaths(vector<vector<int>>& A) {
        m = A.size(), n = A[0].size();
        long long res = m*n;
        vector<vector<long long>> dp(m, vector<long long>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                res = (res+dfs(i, j, dp, A))%MOD;
        return res;
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
    bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        return root->val==2?l||r:l&&r;
    }
};

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& A, vector<int>& B, int c) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int idx = 0;
        bool full;
        for(auto i : A){
            full = true;
            for(int j = 0; j < c; j++){
                if(idx>=B.size() || B[idx]>i){
                    full = false; 
                    break;
                }
                idx++;
            }
        }
        int res = full?B[idx-1]:A.back();
        idx--;
        while(idx>=0 && res==B[idx]) res--, idx--;
        return res;
    }
};

class Solution {
public:
    long long minSumSquareDiff(vector<int>& A, vector<int>& B, int k1, int k2) {
        int n = A.size(), k = k1+k2;
        map<int, int> m;
        for(int i = 0; i < n; i++) m[abs(A[i]-B[i])]++;
        while(k){
            auto it = m.rbegin();
            if(it->first == 0) return 0;
            int i = it->first, j = it->second;
            if(k >= j){
                m.erase(i);
                m[i-1] += j;
                k -= j;
            }
            else{
                m[i] -= k;
                m[i-1] += k;
                k -= k;
            }
            
        }
        long long res = 0;
        for(auto& [i, v] : m) res += (long long)v*i*i;
        return res;
    }
};

class Solution {
private:
    int solve(vector<int>& A, int l, int r, int t){
        if(l > r) return -1;
        int mi = *min_element(A.begin()+l, A.begin()+(r+1));
        double tar = t/(r-l+1);
        if(mi > tar) return r-l+1;
        int prev = l;
        for(int i = l; i <= r; i++){
            if(A[i] <= tar){
                int res = solve(A, prev, i-1, t);
                if(res != -1) return res;
                prev = i+1;
            }
        }
        if(A[r] > tar) return solve(A, prev, r, t);
        return -1;
    }
public:
    int validSubarraySize(vector<int>& A, int t) {
        return solve(A, 0, A.size()-1, t);
    }
};

class Solution {
public:
    int fillCups(vector<int>& A) {
        sort(A.begin(), A.end());
        if(A[0]+A[1] < A[2]) return A[2];
        else return (A[0]+A[1]+A[2])/2+(A[0]+A[1]+A[2])%2;
    }
};

class SmallestInfiniteSet {
private:
    set<int> s;
public:
    SmallestInfiniteSet() {
        for(int i = 1; i < 1005; i++) s.insert(i);
    }
    
    int popSmallest() {
        int res = *s.begin();
        s.erase(s.begin());
        return res;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

class Solution {
public:
    bool canChange(string s1, string s2) {
        string r1, r2;
        for(auto i : s1) if(i != '_') r1 += i;
        for(auto i : s2) if(i != '_') r2 += i;
        if(r1 != r2) return false;
        int n = s1.size(), cnt1 = 0, cnt2 = 0;
        vector<int> pre1(n), pre2(n);
        if(s1[0] == 'L') pre1[0]++;
        if(s1[n-1] == 'R') pre2[n-1]++;
        for(int i = 1; i < n; i++)
            pre1[i] = pre1[i-1]+(s1[i]=='L');
        for(int i = n-2; i >= 0; i--)
            pre2[i] = pre2[i+1]+(s1[i]=='R');
        for(int i = 0; i < n; i++){
            if(s2[i] == 'L') cnt1++;
            if(pre1[i] > cnt1) return false;
        }
        for(int i = n-1; i >= 0; i--){
            if(s2[i] == 'R') cnt2++;
            if(pre2[i] > cnt2) return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& A) {
        vector<int> res(2);
        unordered_map<int, int> m;
        for(auto i : A) m[i]++;
        for(auto& [i, v] : m){
            res[0] += v/2;
            res[1] += v%2;
        }
        return res;
    }
};

class Solution {
private:
    int digit(int n){
        int res = 0;
        while(n) res += n%10, n /= 10;
        return res;
    }
public:
    int maximumSum(vector<int>& A) {
        int res = -1;
        vector<priority_queue<int, vector<int>, greater<int>>> v(100);
        for(auto i : A){
            int k = digit(i);
            v[k].push(i);
            if(v[k].size() > 2) v[k].pop();
        }
        for(auto& i : v){
            if(i.size() < 2) continue;
            int a = i.top(); i.pop();
            int b = i.top(); i.pop();
            res = max(res, a+b);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& A, vector<vector<int>>& Q) {
        vector<int> res(Q.size());
        int m = A.size(), n = A[0].size();
        for(int i = 0; i < Q.size(); i++){
            int k = Q[i][0], t = Q[i][1];
            priority_queue<pair<string, int>> p;
            for(int j = 0; j < m; j++){
                p.push({A[j].substr(n-t), j});
                if(p.size() > k) p.pop();
            }
            res[i] = p.top().second;
        }
        return res;
    }
};

class Solution {
public:
    int minOperations(vector<int>& A, vector<int>& B) {
        int g = B[0];
        for(auto i : B) g = gcd(g, i);
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size(); i++)
            if(g%A[i] == 0) return i;
        return -1;
    }
};

class Solution {
public:
    string bestHand(vector<int>& A, vector<char>& B) {
        vector<string> str{"Flush", "Three of a Kind", "Pair", "High Card"};
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int res = 3;
        if(B[0]==B[1]&&B[1]==B[2]&&B[2]==B[3]&&B[3]==B[4]) res = 0;
        else if(A[0]==A[1]&&A[1]==A[2]) res = 1;
        else if(A[1]==A[2]&&A[2]==A[3]) res = 1;
        else if(A[2]==A[3]&&A[3]==A[4]) res = 1;
        else if(A[0]==A[1]||A[1]==A[2]||A[2]==A[3]||A[3]==A[4]) res = 2;
        return str[res];
    }
};

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& A) {
        long long res = 0, cnt = 0;
        for(auto i : A){
            cnt = i?0:cnt+1;
            res += cnt;
        }
        return res;
    }
};

class NumberContainers {
private:
    unordered_map<int, int> m;
    unordered_map<int, set<int>> s;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(m.count(index)){
            s[m[index]].erase(index);
            if(s[m[index]].size() == 0)
                s.erase(m[index]);
        }
        m[index] = number;
        s[number].insert(index);
    }
    
    int find(int number) {
        if(!s.count(number)) return -1;
        return *s[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

class Solution {
public:
    int shortestSequence(vector<int>& A, int k) {
        int res = 1;
        unordered_set<int> s;
        for(auto i : A){
            s.insert(i);
            if(s.size() == k){
                s.clear();
                res++;
            }
        } 
        return res;
    }
};

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> m;
        for(auto i : s){
            if(m.count(i)) return i;
            m.insert(i);
        }
        return '\0';
    }
};

class Trie{
private:
    int n;
    unordered_map<int, Trie*> m;
public:
    Trie():n(0){}
    void add(vector<int>& A){
        Trie *now = this;
        for(auto i : A){
            if(!now->m.count(i)) now->m[i] = new Trie();
            now = now->m[i];
        }
        now->n++;
    }
    int search(vector<int>& A){
        Trie *now = this;
        for(auto i : A){
            if(!now->m.count(i)) return 0;
            now = now->m[i];
        }
        return now->n;
    }
};
class Solution {
public:
    int equalPairs(vector<vector<int>>& A) {
        int res = 0, n = A.size();
        Trie t;
        for(auto& i : A) t.add(i);
        for(int i = 0; i < n; i++){
            vector<int> tmp(n);
            for(int j = 0; j < n; j++) tmp[j] = A[j][i];
            res += t.search(tmp);
        }
        return res;
    }
};

class FoodRatings {
private:
    unordered_map<string, set<pair<int, string>>> m;
    unordered_map<string, pair<string, int>> info;
public:
    FoodRatings(vector<string>& A, vector<string>& B, vector<int>& C) {
        int n = A.size();
        for(int i = 0; i < n; i++){
            m[B[i]].insert({-C[i], A[i]});
            info[A[i]] = {B[i], -C[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto it = info[food];
        m[it.first].erase({it.second, food});
        m[it.first].insert({-newRating, food});
        info[food] = {it.first, -newRating};
    }
    
    string highestRated(string cuisine) {
        return m[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

class Solution {
public:
    long long countExcellentPairs(vector<int>& A, int k) {
        vector<int> v(32);
        long long res = 0;
        for(auto i : unordered_set<int>(A.begin(), A.end())){
            bitset<32> b(i);
            v[b.count()]++;
        }
        for(int i = 0; i < 32; i++)
            for(int j = 0; j < 32; j++)
                if(i+j >= k) res += (long long)v[i]*v[j];
        return res;
    }
};

class Solution {
public:
    int minimumOperations(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        return s.count(0)?s.size()-1:s.size();
    }
};

class Solution {
public:
    int maximumGroups(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, prev_sum = 0, prev_num = 0, now_sum = 0, now_num = 0;
        for(auto i : A){
            if(now_sum+i>prev_sum && now_num+1>prev_num)
                res++, prev_sum = now_sum+i, prev_num = now_num+1, now_sum = now_num = 0;
            else now_sum += i, now_num++;
        }
        return res;
    }
};

class Solution {
private:
    void go(int node, vector<int>& v, vector<int>& s, vector<int>& A){
        v.push_back(node);
        s[node] = 0;
        while(A[v.back()]!=-1 && s[A[v.back()]]==-1){
            s[A[v.back()]] = v.size();
            v.push_back(A[v.back()]);
        }
    }
public:
    int closestMeetingNode(vector<int>& A, int node1, int node2) {
        int n = A.size(), res = INT_MAX, idx = -1;
        vector<int> v1, v2, s1(n, -1), s2(n, -1);
        go(node1, v1, s1, A);
        go(node2, v2, s2, A);
        for(int i = 0; i < n; i++){
            if(s1[i]==-1 || s2[i]==-1) continue;
            if(max(s1[i],s2[i])<res || max(s1[i],s2[i])==res&&i<idx){
                res = max(s1[i],s2[i]);
                idx = i;
            }
        }
        return res==INT_MAX?-1:idx;
    }
};

class Solution {
public:
    int longestCycle(vector<int>& A) {
        int n = A.size(), res = -1;
        unordered_set<int> seen;
        for(int i = 0; i < n; i++){
            if(seen.count(i)) continue;
            unordered_map<int, int> m;
            m[i] = 0, seen.insert(i);
            int now = i, cnt = 1;
            while(A[now]!=-1 && !seen.count(A[now]))
                now = A[now], m[now] = cnt, seen.insert(now), cnt++;;
            if(m.count(A[now])) res = max(res, cnt-m[A[now]]);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& A, vector<vector<int>>& B) {
        map<int, int> m;
        for(auto& i : A) m[i[0]] += i[1];
        for(auto& i : B) m[i[0]] += i[1];
        vector<vector<int>> res;
        for(auto [i, v] : m)
            res.push_back({i, v});
        return res;
    }
};

class Solution {
public:
    long long countBadPairs(vector<int>& A) {
        unordered_map<int, int> m;
        long long n = A.size(), res = n*(n-1)/2;
        for(int i = 0; i < n; i++) m[i-A[i]]++;
        for(auto [i, v] : m)
            res -= (long long)v*(v-1)/2;
        return res;
    }
};

class Solution {
public:
    long long taskSchedulerII(vector<int>& A, int space) {
        unordered_map<int, long long> m;
        long long res = 0;
        for(auto i : A){
            res++;
            if(m.count(i) && res-m[i]<=space) 
                res += (space-(res-m[i]-1));
            m[i] = res;
        }
        return res;
    }
};

class Solution {
public:
    long long minimumReplacement(vector<int>& A) {
        long long res = 0, n = A.size(), prev = A[n-1];
        for(int i = n-2; i >= 0; i--){
            long long k = A[i]/prev-(A[i]%prev==0);
            res += k;
            prev = A[i]/(k+1);
        }
        return res;
    }
};

class Solution {
public:
    int arithmeticTriplets(vector<int>& A, int d) {
        unordered_set<int> m;
        int res = 0;
        for(auto i : A){
            if(m.count(i-d) && m.count(i-2*d)) res++;
            m.insert(i);
        }
        return res;
    }
};

class Solution {
private:
    int dfs(int idx, vector<vector<int>>& g, unordered_set<int>& r){
        r.insert(idx);
        int res = 1;
        for(auto i : g[idx]){
            if(r.count(i)) continue;
            res += dfs(i, g, r);
        }
        return res;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        for(auto& i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        unordered_set<int> r(restricted.begin(), restricted.end());
        return dfs(0, graph, r);
    }
};

class Solution {
public:
    bool validPartition(vector<int>& A) {
        int n = A.size();
        vector<bool> dp(n);
        if(A[1] == A[0]) dp[1] = true;
        if(n>=3 && (A[2]==A[1]&&A[1]==A[0] || A[2]==A[1]+1&&A[1]==A[0]+1)) dp[2] = true;
        for(int i = 3; i < n; i++){
            if(A[i]==A[i-1] && dp[i-2]) dp[i] = true;
            if(A[i]==A[i-1] && A[i-1]==A[i-2] && dp[i-3]) dp[i] = true;
            if(A[i]==A[i-1]+1 && A[i-1]==A[i-2]+1 && dp[i-3]) dp[i] = true;
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> v(26);
        for(auto c : s){
            int id = c-'a', m = 0;
            for(int i = 0; i < 26; i++){
                if(abs(i-id) > k) continue;
                m = max(m, v[i]);
            }
            v[id] = max(v[id], m+1);
        }
        return *max_element(v.begin(), v.end());
    }
};

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> res(n-2, vector<int>(n-2));
        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < n-2; j++){
                for(int a = i; a < i+3; a++){
                    for(int b = j; b < j+3; b++){
                        res[i][j] = max(res[i][j], A[a][b]);
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int edgeScore(vector<int>& A) {
        int n = A.size();
        vector<long long> S(n);
        for(int i = 0; i < n; i++)
            S[A[i]] += i;
        return max_element(S.begin(), S.end())-S.begin();
    }
};

class Solution {
private:
    void solve(int idx, string& res, string& tmp, string& s, unordered_set<char>& us){
        if(us.empty()){
            if(res=="") res = tmp;
            else res = min(res, tmp);
        }
        unordered_set<char> t(us);
        for(auto i : t){
            if(idx!=0 && (s[idx-1]=='I'&&i<tmp[idx-1] || s[idx-1]=='D'&&i>tmp[idx-1])) continue;
            tmp += i;
            us.erase(i);
            solve(idx+1, res, tmp, s, us);
            us.insert(i);
            tmp.pop_back();
        }
    }
public:
    string smallestNumber(string s) {
        int n = s.size();
        unordered_set<char> us;
        for(int i = 1; i <= n+1; i++)
            us.insert(i+'0');
        string res, tmp;
        solve(0, res, tmp, s, us);
        return res;
    }
};

class Solution {
private:
    vector<int> digit(int n){
        vector<int> res;
        while(n){
            res.push_back(n%10);
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int solve(int idx, int len, vector<int>& d, unordered_set<int>& us, bool equal){
        if(idx == len) return 1;
        if(!equal){
            int p = 1, q = us.size();
            for(int i = idx; i < len; i++)
                p *= q, q--;
            return p;
        }
        int res = 0;
        unordered_set<int> t(us);
        for(auto i : t){
            if(i>d[idx] || idx==0&&i==0) continue;
            us.erase(i);
            res += solve(idx+1, len, d, us, i==d[idx]);
            us.insert(i);
        }
        return res;
    }
public:
    int countSpecialNumbers(int n) {
        if(n < 10) return n;
        vector<int> d = digit(n);
        int len = d.size(), res = 9, p = 9, q = 9;
        for(int i = 2; i <= len-1; i++){
            res += p*q;
            p *= q, q--;
        }
        unordered_set<int> us;
        for(int i = 0; i <= 9; i++) us.insert(i);
        res += solve(0, len, d, us, true);
        return res;
    }
};


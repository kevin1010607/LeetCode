class Solution {
private:
    typedef vector<int>::iterator It;
    It lower(It l, It r, int target){
        int cnt = distance(l, r), step;
        while(cnt > 0){
            step = cnt/2;
            It mid = l+step;
            if(*mid < target) l = ++mid, cnt -= step+1;
            else cnt = step;
        }
        return l;
    }
    It upper(It l, It r, int target){
        int cnt = distance(l, r), step;
        while(cnt > 0){
            step = cnt/2;
            It mid = l+step;
            if(*mid <= target) l = ++mid, cnt -= step+1;
            else cnt = step;
        }
        return l;
    }
public:
    vector<int> searchRange(vector<int>& A, int target) {
        It l = lower(A.begin(), A.end(), target);
        It r = upper(A.begin(), A.end(), target);
        if(l==A.end() || *l!=target) return {-1, -1};
        return {int(l-A.begin()), int(r-A.begin()-1)};
    }
};
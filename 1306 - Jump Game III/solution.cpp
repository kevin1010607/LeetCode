class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start<0 || start>=arr.size() || arr[start]==-1) return false;
        if(arr[start] == 0) return true;
        int l = start-arr[start], r = start+arr[start];
        arr[start] = -1;
        return canReach(arr, l)||canReach(arr, r);
    }
};
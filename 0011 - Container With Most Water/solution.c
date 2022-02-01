#define max(a,b) (((a)>(b))?(a):(b))
int maxArea(int* height, int heightSize){
    int l = 0, r = heightSize-1, res = 0;
    while(l < r){
        if(height[l] < height[r]) res = max(res, (r-l)*height[l]), l++;
        else res = max(res, (r-l)*height[r]), r--;
    }
    return res;
}
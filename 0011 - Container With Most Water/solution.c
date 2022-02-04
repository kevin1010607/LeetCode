#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
int maxArea(int* height, int heightSize){
    int l = 0, r = heightSize-1, res = 0;
    while(l < r){
        int h = min(height[l], height[r]);
        res = max(res, (r-l)*h);
        while(l<r && height[l]<=h) l++;
        while(l<r && height[r]<=h) r--;
    }
    return res;
}
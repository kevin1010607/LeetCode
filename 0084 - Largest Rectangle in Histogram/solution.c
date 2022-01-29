#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
int largestRectangleArea(int* heights, int heightsSize){
    int res = 0, t[100005] = {};
    for(int i = 0; i < heightsSize; i++){
        int h = heights[i];
        for(int j = i; j < heightsSize; j++){
            h = min(h, heights[j]);
            if(h <= t[j]) break;
            t[j] = h;
            res = max(res, h*(j-i+1));
        }
    }
    return res;
}
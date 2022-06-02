#define abs(a) (((a)>0)?(a):(-a))
#define max(a,b) (((a)>(b))?(a):(b))
int findMinMoves(int* A, int n){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += A[i];
    if(sum%n) return -1;
    int target = sum/n, move = 0, res = 0;
    for(int i = 0; i < n; i++){
        move += A[i]-target;
        res = max(res, max(abs(move), A[i]-target));
    }
    return res;
}
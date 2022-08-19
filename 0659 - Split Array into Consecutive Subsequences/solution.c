#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
bool isPossible(int* A, int ASz){
    int pre = INT_MIN, p1 = 0, p2 = 0, p3 = 0;
    for(int i = 0; i < ASz; i++){
        int now = A[i], cnt = 1, n1, n2, n3;
        while(i+1<ASz && A[i+1]==now) cnt++, i++;
        if(now == pre+1){
            if(cnt < p1+p2) return false;
            n1 = max(0, cnt-(p1+p2+p3));
            n2 = p1;
            n3 = p2+min(p3, cnt-(p1+p2));
        }
        else{
            if(p1 || p2) return false;
            n1 = cnt, n2 = n3 = 0;
        }
        pre = now, p1 = n1, p2 = n2, p3 = n3;
    }
    return p1==0 && p2==0;
}
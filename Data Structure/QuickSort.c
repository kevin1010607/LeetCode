void swap(int *a, int *b){int t=*a; *a=*b; *b=t;}
void quickSort(int *a, int l, int r){
    if(l >= r) return;
    int i = l+1, j = r, p = a[l];
    while(1){
        while(j>=l+1 && a[j]>=p) j--;
        while(i<=r && a[i]<=p) i++;
        if(i >= j) break;
        swap(a+i, a+j);
    }
    swap(a+l, a+j);
    quickSort(a, l, j-1);
    quickSort(a, j+1, r);
}
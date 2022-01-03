int findJudge(int n, int** trust, int trustSize, int* trustColSize){
    int v[1005] = {};
    for(int i = 0; i < trustSize; i++)
        v[trust[i][0]]--, v[trust[i][1]]++;
    for(int i = 1; i <= n; i++) if(v[i] == n-1) return i;
    return -1;
}
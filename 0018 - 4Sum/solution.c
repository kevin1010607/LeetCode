typedef struct{
    int **a, *rsize, *rcp, size, cp;
}Vector2d;

Vector2d* newVector2d(int, int, int, int, int);
void doubleSize(Vector2d*);
void doubleRowSize(Vector2d*, int);
bool empty(Vector2d*);
bool emptyRow(Vector2d*, int);
bool full(Vector2d*);
bool fullRow(Vector2d*, int);
int getSize(Vector2d*);
int getRowSize(Vector2d*, int);
int** getArray(Vector2d*);
int* getArraySize(Vector2d*);
int getElement(Vector2d*, int, int);
void modifyByAdd(Vector2d*, int, int, int);
void modifyByVal(Vector2d*, int, int, int);
void pushBack(Vector2d*);
void pushRowBack(Vector2d*, int, int);
void popRowBack(Vector2d*, int);
void freeVector2d(Vector2d*);

Vector2d* newVector2d(int size, int cp, int rsize, int rcp, int val){
    Vector2d *res = (Vector2d*)malloc(sizeof(Vector2d));
    res->a = (int**)malloc(cp*sizeof(int*));
    res->rsize = (int*)malloc(cp*sizeof(int));
    res->rcp = (int*)malloc(cp*sizeof(int));
    res->size = size, res->cp = cp;
    for(int i = 0; i < cp; i++){
        res->a[i] = (int*)malloc(rcp*sizeof(int));
        res->rsize[i] = i<size?rsize:0;
        res->rcp[i] = rcp;
    }
    for(int i = 0; i < size; i++) for(int j = 0; j < rsize; j++) res->a[i][j] = val;
    return res;
}
void doubleSize(Vector2d *v){
    int n = v->cp*2;
    v->a = (int**)realloc(v->a, n*sizeof(int*));
    v->rsize = (int*)realloc(v->rsize, n*sizeof(int));
    v->rcp = (int*)realloc(v->rcp, n*sizeof(int));
    for(int i = v->cp; i < n; i++){
        v->a[i] = (int*)malloc(v->rcp[0]*sizeof(int));
        v->rsize[i] = 0, v->rcp[i] = v->rcp[0];
    }
    v->cp = n;
}
void doubleRowSize(Vector2d *v, int r){
    v->rcp[r] *= 2;
    v->a[r] = (int*)realloc(v->a[r], v->rcp[r]*sizeof(int));
}
bool empty(Vector2d *v){
    return v->size==0;
}
bool emptyRow(Vector2d *v, int r){
    return v->rsize[r]==0;
}
bool full(Vector2d *v){
    return v->size==v->cp;
}
bool fullRow(Vector2d *v, int r){
    return v->rsize[r]==v->rcp[r];
}
int getSize(Vector2d *v){
    return v->size;
}
int getRowSize(Vector2d *v, int r){
    return v->rsize[r];
}
int** getArray(Vector2d *v){
    return v->a;
}
int* getArraySize(Vector2d *v){
    return v->rsize;
}
int getElement(Vector2d *v, int r, int c){
    return v->a[r][c];
}
void modifyByAdd(Vector2d *v, int r, int c, int dval){
    v->a[r][c] += dval;
}
void modifyByVal(Vector2d *v, int r, int c, int val){
    v->a[r][c] = val;
}
void pushBack(Vector2d *v){
    if(full(v)) doubleSize(v);
    v->size++;
}
void pushRowBack(Vector2d *v, int r, int val){
    if(fullRow(v, r)) doubleRowSize(v, r);
    v->a[r][v->rsize[r]++] = val;
}
void popRowBack(Vector2d *v, int r){
    if(emptyRow(v, r)) return;
    v->rsize[r]--;
}
void freeVector2d(Vector2d *v){
    for(int i = 0; i < v->cp; i++) free(v->a[i]);
    free(v->a);
    free(v->rsize);
    free(v->rcp);
    free(v);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {return *(const int*)a-*(const int*)b;}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int n = numsSize;
    Vector2d *v = newVector2d(0, 105, 0, 4, 0);
    qsort(nums, n, sizeof(int), cmp);
    for(int i = 0; i < n-3; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        if((long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
        if((long long)nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
        for(int j = i+1; j < n-2; j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            if((long long)nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
            if((long long)nums[i]+nums[j]+nums[n-1]+nums[n-2] < target) continue;
            int l = j+1, r = n-1;
            while(l < r){
                long long s = (long long)nums[i]+nums[j]+nums[l]+nums[r];
                if(s == target){
                    pushBack(v);
                    pushRowBack(v, getSize(v)-1, nums[i]);
                    pushRowBack(v, getSize(v)-1, nums[j]);
                    pushRowBack(v, getSize(v)-1, nums[l]);
                    pushRowBack(v, getSize(v)-1, nums[r]);
                    do{l++;}while(l<r && nums[l]==nums[l-1]);
                    do{r--;}while(l<r && nums[r]==nums[r+1]);
                }
                else s<target?(l++):(r--);
            }
        }
    }
    int **res = getArray(v);
    *returnColumnSizes = getArraySize(v);
    *returnSize = getSize(v);
    // FreeVector2d(v);
    return res;
}
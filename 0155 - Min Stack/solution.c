#define SIZE 100
typedef struct {
    int *stack;
    int min, top, capacity;
} MinStack;
MinStack* minStackCreate() {
    MinStack *ret = (MinStack*)malloc(sizeof(MinStack));
    ret->stack = (int*)malloc(SIZE*sizeof(int));
    ret->min = INT_MAX, ret->top = 0, ret->capacity = SIZE;
    return ret;
}
void doubleSize(MinStack* obj){
    int *s = (int*)malloc((obj->capacity*2)*sizeof(int));
    for(int i = 0 ; i < obj->capacity; i++) s[i] = obj->stack[i];
    free(obj->stack);
    obj->stack = s, obj->capacity *= 2;
}
void minStackPush(MinStack* obj, int val) {
    if(obj->top == obj->capacity) doubleSize(obj);
    if(val <= obj->min){
        obj->stack[obj->top++] = obj->min;
        obj->min = val;
    }
    obj->stack[obj->top++] = val;
}
void minStackPop(MinStack* obj) {
    if(obj->top == 0) return;
    if(obj->stack[obj->top-1] == obj->min){
        obj->top--;
        obj->min = obj->stack[obj->top-1];
    }
    obj->top--;
}
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top-1];
}
int minStackGetMin(MinStack* obj) {
    return obj->min;
}
void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
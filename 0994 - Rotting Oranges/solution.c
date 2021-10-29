typedef struct{
    int x[105], y[105];
    int rear, front, capacity;
}Queue;
Queue* newQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    for(int i = 0; i < 105; i++) q->x[i] = q->y[i] = 0;
    q->capacity = 105;
    q->rear = q->front = q->capacity-1;
    return q;
}
int queueEmpty(Queue *q){
    return q->front == q->rear;
}
int queueSize(Queue *q){
    return (q->rear>=q->front)?(q->rear-q->front):(q->capacity-q->front+q->rear);
}
int queueFrontX(Queue *q){
    if(queueEmpty(q)) return -1;
    return q->x[(q->front+1)%q->capacity];
}
int queueFrontY(Queue *q){
    if(queueEmpty(q)) return -1;
    return q->y[(q->front+1)%q->capacity];
}
void queuePush(Queue *q, int i, int j){
    if((q->rear+1)%q->capacity == q->front) return;
    q->rear = (q->rear+1)%q->capacity;
    q->x[q->rear] = i, q->y[q->rear] = j;
}
void queuePop(Queue *q){
    if(queueEmpty(q)) return;
    q->front = (q->front+1)%q->capacity;
}
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int n = gridSize, m = gridColSize[0], time = 0, c = 0;
    Queue *q = newQueue();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2) queuePush(q, i, j);
            else if(grid[i][j] == 1) c++;
        }
    }
    while(!queueEmpty(q)){
        int k = queueSize(q), p = 0;
        while(k--){
            int x = queueFrontX(q), y = queueFrontY(q);
            int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
            queuePop(q);
            for(int i = 0 ; i < 4; i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]!=1) continue;
                grid[nx][ny] = 2, p = 1, c--;
                queuePush(q, nx, ny);
            }
        }
        time += p;
    }
    free(q);
    return c?-1:time;
}
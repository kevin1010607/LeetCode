/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    struct ListNode *head;   
} Solution;
Solution* solutionCreate(struct ListNode* head) {
    Solution *res = (Solution*)malloc(sizeof(Solution));
    res->head = head;
    return res;
}
int solutionGetRandom(Solution* obj) {
    int res = 0, idx = 1;
    for(struct ListNode *now = obj->head; now; now = now->next){
        if(rand()%idx == 0) res = now->val;
        idx++;
    }
    return res;
}
void solutionFree(Solution* obj) {}
/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
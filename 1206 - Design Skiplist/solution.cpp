class Skiplist {
private:
    struct ListNode{
        int val;
        ListNode *next, *down;
        ListNode(): val(-1), next(nullptr), down(nullptr) {}
        ListNode(int x, ListNode *n, ListNode *d): val(x), next(n), down(d) {}
    };
    ListNode *head;
public:
    Skiplist(): head(new ListNode()) {}
    bool search(int target) {
        for(ListNode *now = head; now; now = now->down){
            for(; now->next && now->next->val<target; now = now->next);
            if(now->next && now->next->val==target) return true;
        }
        return false;
    }
    void add(int num) {
        vector<ListNode*> v;
        for(ListNode *now = head; now; now = now->down){
            for(; now->next && now->next->val<num; now = now->next);
            v.push_back(now);
        }
        bool flag = true;
        ListNode *down = nullptr;
        for(int i = v.size()-1; i>=0 && flag; i--, flag = rand()&1){
            down = v[i]->next = new ListNode(num, v[i]->next, down);
        }
        if(flag) head = new ListNode(0, new ListNode(num, nullptr, down), head);
    }
    bool erase(int num) {
        bool res = false;
        for(ListNode *now = head; now; now = now->down){
            for(; now->next && now->next->val<num; now = now->next);
            if(now->next && now->next->val==num){
                res = true;
                auto *tmp = now->next;
                now->next = tmp->next;
                delete tmp;
            }
        }
        return res;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
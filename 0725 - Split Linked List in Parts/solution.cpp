/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        int n = 0;
        ListNode *now = head, *tmp = head;
        while(tmp) tmp = tmp->next, n++;
        for(int i = 0; i < k; i++){
            int t = n/k+(bool)(n/k*k+i<n)-1;
            head = now;
            while(t-- && now) now = now->next;
            if(now) tmp = now, now = now->next, tmp->next = nullptr;
            res[i] = head;
        }
        return res;
    }
};
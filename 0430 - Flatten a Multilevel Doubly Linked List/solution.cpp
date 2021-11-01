/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *now = head, *o, *tmp;
        while(now){
            if(now->child){
                o = now->next;
                now->next = now->child;
                now->next->prev = now;
                now->child = nullptr;
                tmp = now;
                while(tmp->next) tmp = tmp->next;
                tmp->next = o;
                if(o) o->prev = tmp;   
            }
            now = now->next;
        }
        return head;
    }
};
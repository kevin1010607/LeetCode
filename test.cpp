#include<iostream>
#define J -1
using namespace std;
class List{
    class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode(int val):val(val), next(NULL){}
    };
private:
    int jokerNum;
    ListNode *head;
public:
    List(bool Joker, int num):jokerNum(Joker?1:0){
        this->head = new ListNode(0);
        this->head->next = new ListNode(Joker?J:1);
        ListNode *now = this->head->next;
        for(int i = 2; i <= num; i++){
            now->next = new ListNode(i);
            now = now->next;
        }
    }
    bool hasJoker(){
        return jokerNum!=0;
    }
    void insertNode(int val, int idx){
        idx--;
        ListNode *now = this->head;
        while(idx-- && now->next) now = now->next;
        ListNode *ins = new ListNode(val);
        ins->next = now->next;
        now->next = ins;
        if(val == J) this->jokerNum++;
    }
    int deleteNode(int idx){
        idx--;
        ListNode *now = this->head;
        while(idx-- && now->next->next) now = now->next;
        ListNode *tmp = now->next;
        now->next = now->next->next;
        int ret = tmp->val;
        delete tmp;
        if(ret == J) this->jokerNum--;
        return ret;
    }
    void printNode(){
        if(this->head->next == NULL){
            cout << "\n";
            return;
        }
        ListNode *now = this->head->next;
        while(now->next){
            cout << now->val << " ";
            now = now->next;
        }
        cout << now->val << "\n";
    }
};
int n, m, k, a, b, A = 1, B = 2, id = 1;
bool joker[105];
List *list[105];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    while(k--) {cin >> a; joker[a] = true;}
    for(int i = 1; i <= n; i++) list[i] = new List(joker[i], m);
    while(cin>>a>>b && a!=-1 && b!=-1){
        int val = list[B]->deleteNode(a);
        list[A]->insertNode(val, b);
        A = (A+1-1)%n+1, B = (B+1-1)%n+1;
    }
    while(list[id]->hasJoker()) id++;
    list[id]->printNode();
    for(int i = 1; i <= n; i++) delete list[i];
    return 0;
}
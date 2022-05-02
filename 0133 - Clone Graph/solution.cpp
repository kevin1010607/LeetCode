/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        queue<Node*> q;
        unordered_map<Node*, Node*> m;
        m[node] = new Node(node->val);
        q.push(node);
        while(!q.empty()){
            Node *now = q.front(); q.pop();
            for(auto i : now->neighbors){
                if(!m.count(i)) {m[i] = new Node(i->val); q.push(i);}
                m[now]->neighbors.push_back(m[i]);
            }
        }
        return m[node];
    }
};
class MinStack {
private:
    stack<int> s;
    int min_val = INT_MAX;
public:
    MinStack() {}
    void push(int val) {
        if(val <= min_val){
            s.push(min_val);
            min_val = val;
        }
        s.push(val);
    }
    void pop() {
        if(s.top() == min_val){
            s.pop();
            min_val = s.top();
        }
        s.pop();
    }
    int top() {
        return s.top();    
    }
    int getMin() {
        return min_val;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
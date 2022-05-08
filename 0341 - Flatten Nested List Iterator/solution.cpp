/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &A) {
        for(auto it = A.rbegin(); it != A.rend(); it++)
            s.push(*it);
    }
    
    int next() {
        int res = s.top().getInteger(); s.pop();
        return res;
    }
    
    bool hasNext() {
        while(!s.empty()){
            if(s.top().isInteger()) return true;
            auto v = s.top().getList(); s.pop();
            for(auto it = v.rbegin(); it != v.rend(); it++)
                s.push(*it);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
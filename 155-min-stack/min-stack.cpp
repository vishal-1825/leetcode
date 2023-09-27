class MinStack {
private:
    vector<pair<int, int>> st;
    int size;
public:
    MinStack() {
        size=0;
    }
    
    void push(int val) {
        if (st.empty()) st.push_back({val, val});
        else st.push_back({val, min(st[size-1].second, val)});
        size++;
    }
    
    void pop() {
        if (size>0)
        {
            st.pop_back();
            size--;
        }
    }
    
    int top() {
        return st[size-1].first;
    }
    
    int getMin() {
        return st[size-1].second;
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
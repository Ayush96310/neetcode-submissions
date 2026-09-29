class MinStack {
public:
    int mini;
    stack<pair<int,int>> st;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        mini = min(mini,val);
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
        if(!st.empty()) mini = st.top().second;
        else mini = INT_MAX;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return mini;
    }
};

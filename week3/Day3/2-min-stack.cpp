class MinStack {
private:
    // The stack holds pairs: {value, min value so far}
    stack<pair<int, int>> st;

public:
    MinStack() {
        // Constructor stays empty since stack handles its own initialization
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        return st.top().first; // .first gets the actual value
    }
    
    int getMin() {
        return st.top().second; // .second gets the tracked minimum value
    }
};
// this can also be done using two stacks, one for the values and another for the minimums
// but this implementation is more space-efficient since it only uses one stack.
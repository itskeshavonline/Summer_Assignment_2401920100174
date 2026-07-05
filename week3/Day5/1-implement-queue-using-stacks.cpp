class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {
        // Constructor can be left as it is
    }
    
    // Time Complexity: O(n)
    void push(int x) {
        // Step 1: Copy all elements from s1 to s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2: Push the new element into s1
        s1.push(x);

        // Step 3: Copy all elements back from s2 to s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    // Time Complexity: O(1)
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    // Time Complexity: O(1)
    int peek() {
        return s1.top();
    }
    
    // Time Complexity: O(1)
    bool empty() {
        return s1.empty();
    }
};
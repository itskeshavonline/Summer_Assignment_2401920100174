// optimal
class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
        // Constructor initialization
    }
    
    int ping(int t) {
        q.push(t); // Step 1: enqueue the new request timestamp
        
        // Step 2: Remove timestamps outside of the 3000ms time frame window
        while (!q.empty() && (t - 3000) > q.front()) {
            q.pop();
        }
        
        // Step 3: elements remaining in the queue
        // total valid pings within the frame
        return q.size(); 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
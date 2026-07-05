class RecentCounter {
private:
    vector<int> list;
    int i; // Left pointer tracking the start of the 3000ms window
    int j; // Right pointer tracking the end of the 3000ms window

public:
    RecentCounter() {
        i = 0; // from 1st index
        j = -1; // from empty space
    }
    
    int ping(int t) {
        list.push_back(t); // Step 1: Add the current timestamp to our list
        j++;
        
        // Step 2: Shrink the window from the left if the oldest timestamp 'list[i]' 
        // falls outside the valid time range [t - 3000, t]
        while (i < j && (list[j] - 3000) > list[i]) {
            i++; // Moving the left boundary forward to exclude out-of-range elements
        }
        
        // Step 3: elements in valid time range
        return j - i + 1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
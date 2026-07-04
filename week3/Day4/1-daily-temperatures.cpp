class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // default 0 if no warmer day is found)
        stack<int> st;         // To store the INDICES of the days
        
        for (int i = 0; i < n; i++) {
            // While the current day's temperature is warmer than the day at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                
                // The waiting time
                ans[prevIndex] = i - prevIndex;
            }
            
            st.push(i); // current day's index onto the stack
        }
        
        return ans;
    }
};
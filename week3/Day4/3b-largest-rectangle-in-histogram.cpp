// optimized approach using monotonic stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        // Vectors to store index of the nearest smaller element on left and right
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        stack<int> st;

        // Step 1: Calculate Right Smaller (Next Smaller Element) indices
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            // If no right smaller element exists, cap it at boundary index 'n'
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear the stack to reuse it for the left side calculation
        while (!st.empty()) {
            st.pop();
        }

        // Step 2: Calculate Left Smaller (Previous Smaller Element) indices
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            // If no left smaller element exists, cap it at boundary index '-1'
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Step 3: Compute the maximum area using the computed boundaries
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int current_height = heights[i];
            int width = right[i] - left[i] - 1;
            int current_area = current_height * width;
            max_area = max(max_area, current_area);
        }

        return max_area;
    }
};
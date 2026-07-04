// brute force approach but gives TLE
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        int maxarea = 0;

        for (int i = 0; i < n; i++) {
            // rectangl's movement towards right
            int j = i;
            while (j < n && heights[j] >= heights[i]) {
                j++;
            }
            //at exit, jth index is the 1st shorter bar towards right

            // rectangle's movement towards left
            int l = i;
            while (l >= 0 && heights[l] >= heights[i]) {
                l--;
            }
            //at exit, ith index is the 1st shorter bar towards left

            // The width : boundary difference: (j - 1) - (l + 1) + 1
            int width = j - l - 1;
            int area = heights[i] * width;
            maxarea = max(area, maxarea);
        }

        return maxarea;
    }
};
// uses monotonic deque and makes TC O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> window; // Will store indices of elements
        vector<int> max_win;
        max_win.reserve(n - k + 1);

        for (int i = 0; i < n; i++) {
            // 1. Remove indices that are out of the current window bound [i - k + 1, i]
            if (!window.empty() && window.front() == i - k) {
                window.pop_front();
            }

            // 2. Remove elements from the back that are smaller than the current element nums[i]
            // They are useless to us because nums[i] is larger and will outlive them
            // For monotonic deque which is strictly decreasing
            while (!window.empty() && nums[window.back()] <= nums[i]) {
                window.pop_back();
            }

            // 3. Add current element's index to the back of the deque
            window.push_back(i);

            // 4. Once we have hit our first full window size 'k', append the maximum
            if (i >= k - 1) {
                max_win.push_back(nums[window.front()]);
            }
        }

        return max_win;
    }
};
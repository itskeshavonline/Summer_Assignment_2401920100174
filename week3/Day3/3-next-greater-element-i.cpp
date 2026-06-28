class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> next_greater;
        
        // 1. Finding the next greater element for every number in nums2
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        // 2. the answer vector for nums1 
        vector<int> ans;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                ans.push_back(next_greater[num]);
            } else {
                ans.push_back(-1); // No greater element found
            }
        }
        
        return ans;
    }
};
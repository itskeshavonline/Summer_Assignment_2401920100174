class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      
        int n = nums.size();
        int currsum=nums[0],bestsum=nums[0];

        for (int i = 1; i < n; i++) {
        currsum=max(nums[i],currsum+nums[i]);
        bestsum=max(bestsum,currsum);
        }
        return bestsum;
    }
};
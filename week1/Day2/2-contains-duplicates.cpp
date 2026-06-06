class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
    }
}; 
//this problem can also be solved using hashset which is efficient in terms of time complexity and sorting is more efficient in terms of space complexity.
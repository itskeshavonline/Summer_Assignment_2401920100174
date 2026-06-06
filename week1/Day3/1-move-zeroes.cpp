class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),writeIndex=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[writeIndex++]=nums[i];   
            }
        }
        for(int i=writeIndex;i<n;i++){
            nums[i]=0;
        }
    }
};
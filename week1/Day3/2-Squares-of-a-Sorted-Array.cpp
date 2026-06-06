class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1,writeIndex=n-1;
        vector<int> squareArr(n);
        while(left<=right){
            if(nums[left]*nums[left]<nums[right]*nums[right]){
                squareArr[writeIndex--]=nums[right]*nums[right];
                right--;
            }else{
                squareArr[writeIndex--]=nums[left]*nums[left];
                left++;
            }
        }
        return squareArr;
    }
};
//two pointer approach

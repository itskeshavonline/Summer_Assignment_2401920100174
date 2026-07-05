// it has time complexity O(n*k) and gives TLE
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> window;
        vector<int> max_win;
        max_win.reserve(n-k+1);


        int maxi=INT_MIN;

        for(int i=0;i<k;i++){
            maxi=max(nums[i],maxi);
            window.push_back(nums[i]);
        }

        max_win.push_back(maxi);

        for(int i=k;i<n;i++){
            
            window.pop_front();
            window.push_back(nums[i]);

            maxi=INT_MIN;
            for(int val: window){
                maxi=max(maxi, val);
            }
            max_win.push_back(maxi);
        }

        return max_win;
    }
};
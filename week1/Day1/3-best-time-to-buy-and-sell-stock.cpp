class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size(),i=0,bestbuy=arr[0];
        int maxprofit=0;
        for(i=1;i<n;i++){
            if(arr[i]>bestbuy){
                maxprofit=max(maxprofit,arr[i]-bestbuy);
            }
            bestbuy=min(bestbuy,arr[i]);
        }return maxprofit;      
    }
};
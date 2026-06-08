class Solution {
public:
   vector<int> spiralOrder(vector<vector<int>>& arr) {
    if (arr.empty()) return {};
    
    int m = arr.size();    
    int n = arr[0].size(); 
    
    int l = 0, s = n - 1;
    int u = 0, t = m - 1;
    
    vector<int> ans;
    int totalElements = m * n;
    int k = 0;

    while (k < totalElements) {
        for (int i = l; i <= s && k < totalElements; i++) {
            ans.push_back(arr[u][i]);
            k++;
        }
        u++; 
        for (int j = u; j <= t && k < totalElements; j++) {
            ans.push_back(arr[j][s]);
            k++;
        }
        s--;
        for (int i = s; i >= l && k < totalElements; i--) {
            ans.push_back(arr[t][i]);
            k++;
        }
        t--; 
        for (int j = t; j >= u && k < totalElements; j--) {
            ans.push_back(arr[j][l]); 
            k++;
        }
        l++; 
    }
    
    return ans;
}
};
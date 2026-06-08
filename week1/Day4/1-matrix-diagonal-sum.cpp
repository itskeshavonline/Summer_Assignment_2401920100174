class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int prisum=0,secsum=0,totalsum;
        int h=n/2;
        for(int i=0;i<n;i++){
            prisum+=mat[i][i];
            secsum+=mat[i][n-i-1];
        }
        if(n%2!=0) secsum-=mat[h][h];
        totalsum=prisum+secsum;
        return totalsum;
    }
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(),n=mat[0].size();
        if((m*n)!=(r*c)) return mat;
        int originalRow,originalCol;
        int newRow,newCol;
        vector<vector<int>> newmat(r, vector<int>(c));
        for(int i=0;i<m*n;i++){
            originalRow=i/n;  // Calculate the original row index
            originalCol=i%n;  // Calculate the original column index
            newRow=i/c;
            newCol=i%c;
            newmat[newRow][newCol]=mat[originalRow][originalCol];
        }
        return newmat;
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
    
    void backtrack(vector<string>& ans, string current, int openCount, int closeCount, int n) {
        // Base case: combination is complete
        if (current.size() == n * 2){
            ans.push_back(current);
            return;
        }
        
        // Add open parenthesis if available
        if (openCount < n){
            backtrack(ans, current + "(", openCount + 1, closeCount, n);
        }
        
        // Add close parenthesis if it balances an open one
        if (closeCount < openCount){
            backtrack(ans, current + ")", openCount, closeCount + 1, n);
        }
    }
};
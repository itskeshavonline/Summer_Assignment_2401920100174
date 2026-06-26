class Solution {
private:
    //returns -1, 1, & 0 for not checked, palindrome, & not palindrome respectively
    int solve(int L, int R, const string& s, vector<vector<int>>& dp) {
        if (L >= R) return 1;
        if (dp[L][R] != -1) return dp[L][R];

        if (s[L] == s[R]) {
            return dp[L][R] = solve(L + 1, R - 1, s, dp);
        }
        return dp[L][R] = 0;
    }

public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int maxLength = 1;
        int startIdx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(i, j, s, dp) == 1) {
                    int currentLength = j - i + 1;
                    if (currentLength > maxLength) {
                        maxLength = currentLength;
                        startIdx = i;
                    }
                }
            }
        }
        return s.substr(startIdx, maxLength);
    }
};
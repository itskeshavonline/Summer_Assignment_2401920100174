class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        
        for (int len = 1; len <= n / 2; len++) {
            // Check if len divides total length perfectly
            if (n % len == 0) {
                string sub = s.substr(0, len);
                string rebuilt = "";
                
                int numRepeats = n / len;
                for (int i = 0; i < numRepeats; i++) {
                    rebuilt += sub;
                }
                
                if (rebuilt == s) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
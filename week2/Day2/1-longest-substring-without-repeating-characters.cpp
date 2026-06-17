class Solution {
public:
   int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int hash[256] = {0};  // re‑initialized for each i
            for (int j = i; j < n; j++) {
                if (hash[(unsigned char)s[j]] == 1) {
                    // character s[j] already seen in this substring
                    break;
                }
            hash[(unsigned char)s[j]] = 1;
            int len = j - i + 1;
            maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
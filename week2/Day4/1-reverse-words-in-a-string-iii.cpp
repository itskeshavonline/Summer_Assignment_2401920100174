class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        int temp;
        
        for (int i = 0; i <= n; i++) {
            // Check if we reached a space or the end of the string
            if (i == n || s[i] == ' ') {
                int st = start;
                int end = i - 1;
                
                // To reverse words
                while (st < end) {
                    temp = s[st];
                    s[st] = s[end];
                    s[end] = temp;
                    st++;
                    end--;
                }
                
                // Move start to the beginning of the next word
                start = i + 1;
            }
        }
        
        return s;
    }
};
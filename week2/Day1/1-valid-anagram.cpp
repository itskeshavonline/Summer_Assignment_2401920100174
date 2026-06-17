class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int charCounts[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            charCounts[s[i] - 'a']++;
        }
        for (int j = 0; j < t.size(); j++) {
            charCounts[t[j] - 'a']--;
            if (charCounts[t[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
        }
};
// it can also be solved by sorting both strings and 
// comparing them 
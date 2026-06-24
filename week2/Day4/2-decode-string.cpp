class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return helper(s, index);
    }
    
    string helper(const string& s, int& i){
        string res = "";
        int num = 0;
        
        while (i < s.size()){
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                i++; // Skip '['
                string nestedStr = helper(s, i);
                for (int j = 0; j < num; j++) {
                    res += nestedStr;
                }
                num = 0; // Reset
            } else if (s[i] == ']') {
                return res; // End of current recursive context segment
            } else {
                res += s[i];
            }
            i++;
        }
        return res;
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; 
        int i = 0;
        
        while (i < n) {
            int j = i;
            
            // Finding the end of the current repeating group
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            
            int count = j - i;
            chars[index] = chars[i]; // Write the character
            index++;
            
            // If character repeats, write its count split into digits
            if (count > 1) {
                string countStr = to_string(count);
                for (int k = 0; k < countStr.size(); k++) {
                    chars[index] = countStr[k];
                    index++;
                }
            }
            
            i = j; // Move read pointer to the next group
        }
        
        return index;
    }
};
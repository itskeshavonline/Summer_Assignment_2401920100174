class Solution {
public:
    string longestCommonPrefix(vector<string>& s){
        if(s.empty()){
            return "";
        }
        string base = s[0];
    
        for(int j = 0; j < base.size(); j++){
            char currentChar = base[j];
        
            for(int i = 1; i < s.size(); i++){
                if(j >= s[i].size() || s[i][j] != currentChar){
                    return base.substr(0, j);
                }
            }
        }
        return base;
    }
};
//this implementaton solves the problem by column by column vertical scanning(comparing)

//this problem can also be solved by sorting the array of strings alphabetically
//in this, the two strings that are most different from each other will end up at the very beginning (first) and the very end (last) of the sorted array
// Only compare the first and last strings and ignore middle ones
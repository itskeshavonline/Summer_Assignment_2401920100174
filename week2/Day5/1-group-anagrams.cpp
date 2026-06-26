class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map; 
        
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());//creating the unnique key
            map[word].push_back(strs[i]);//grouping the anagrams
        }
        
        vector<vector<string>> ans;
        
        for (pair<string, vector<string>> group : map) {
            ans.push_back(group.second); // group.second is the vector of strings
        }
        
        return ans;
    }
};
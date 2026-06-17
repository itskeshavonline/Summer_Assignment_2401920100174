class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        int freq[26]={0};
        
        if(m<n) return false;
        
        for(int i=0;i<m;i++){
            freq[magazine[i]-'a']++;
        }
        
        for(int i=0;i<n;i++){
            freq[ransomNote[i]-'a']--;
            if(freq[ransomNote[i]-'a']<0){
                return false;
            }
        }
        return true;
    }
};
// it can also be solved by sorting both strings and 
// comparing them by two pointers 
// but sorting takes O(nlogn+mlogm) tc which is less efficient. 
// the above solution is more efficient with O(n+m) tc.
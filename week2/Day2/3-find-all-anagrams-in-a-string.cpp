class Solution {
public:
    vector<int> findAnagrams(string s, string p){
        int n=p.size(), m=s.size();
        vector<int> index;

        if(m<n) {
            return index;
        }

        int freq1[26]={0};
        int freq2[26]={0};
        
        for(int i=0;i<n;i++){
            freq1[p[i]-'a']++;
            freq2[s[i]-'a']++;
        }
        
        bool match=true;
        for(int k=0;k<n;k++){
            if(freq1[p[k]-'a']!=freq2[p[k]-'a']){
                match=false;
                break;
            }
        }
        if(match)  index.push_back(0);;
        
        for(int i=n;i<m;i++){
            freq2[s[i]-'a']++;       // Add NEW character in front
            freq2[s[i-n]-'a']--;     // remove OLD character from back

            match=true;
            for(int k=0;k<n;k++){
                if(freq1[p[k]-'a']!=freq2[p[k]-'a']){
                    match=false;
                    break;
                }
            }
            if(match)  index.push_back(i-n+1);
            //i-n is the index for removing old character
            //so i-n+1 is the starting index for the new anagram
        }
        
        return index;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        
        if(m<n) return false;
        
        int freq1[26]={0};
        int freq2[26]={0};
        
        for(int i=0;i<n;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        
        bool match=true;
        for(int k=0;k<n;k++){
            if(freq1[s1[k]-'a']!=freq2[s1[k]-'a']){
                match=false;
                break;
            }
        }
        if(match) return true;
        
        for(int i=n;i<m;i++){
            freq2[s2[i]-'a']++;       // Add NEW character in front
            freq2[s2[i-n]-'a']--;     // remove OLD character from back

            match=true;
            for(int k=0;k<n;k++){
                if(freq1[s1[k]-'a']!=freq2[s1[k]-'a']){
                    match=false;
                    break;
                }
            }
            if(match) return true;
        }
        
        return false;
    }
};
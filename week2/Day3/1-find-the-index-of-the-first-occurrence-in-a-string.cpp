class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(), m=needle.size();
        
        if(m>n) return -1;
        
        // for the movement of the sliding window
        // where i is the starting index of the window in haystack
        for(int i=0; i<=n-m; i++){ 
            int j=0;
            
            // in while loop, i+j is for the current index in haystack
            // j is the current index in needle(window)
            while(j<m && haystack[i+j]==needle[j]){
                j++;
            }
            
            if(j==m) return i;
        }
        
        return -1;
    }
};
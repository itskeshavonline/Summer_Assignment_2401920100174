class Solution {
public:
    bool isPalindrome(string s) {
        int i,n=s.size();
        string s2;
        for(i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9'){
                s2.push_back(tolower(s[i]));
                
            }
        }
        string s3=s2;
        reverse(s2.begin(), s2.end());
       return s2==s3;
    }
};
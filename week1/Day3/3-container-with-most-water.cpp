class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        long long currwater=0,maxwater=0,ht,w;
        while(i<j){
            ht=min(height[i],height[j]);
            w=j-i;
            currwater=ht*w;
            maxwater=max(maxwater,currwater);
            (height[i]<height[j])?i++:j--;
        }return (int)maxwater;
        
    }
};
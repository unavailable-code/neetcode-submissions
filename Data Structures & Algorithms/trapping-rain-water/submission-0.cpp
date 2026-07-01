class Solution {
public:
    int trap(vector<int>& heights) {
        int l=0,leftMax=heights[0],r=heights.size()-1,rightMax=heights[heights.size()-1],rain=0;
    while(l<r){
        if(leftMax<=rightMax){
            rain=rain+leftMax-heights[l];
            l++;
        }
        else{
            rain=rain+rightMax-heights[r];
            r--;
        }
        leftMax=max(leftMax,heights[l]);
        rightMax=max(rightMax,heights[r]);
    }
    return rain;
    }
};

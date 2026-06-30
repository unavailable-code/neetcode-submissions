class Solution {
public:
    int maxArea(vector<int>& nums) {
    int l=0,r=nums.size()-1;
    int water=0;
    while(l<r){
        water=max(water,(r-l)*min(nums[r],nums[l]));
        if(nums[l]>nums[r]){
            r--;
        }
        else{
            l++;
        }
    }
    return water;
    }
};

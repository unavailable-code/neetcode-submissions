class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        for(int i=0;i<nums.size();i++){
        int b=0,e=nums[0].size()-1;
        while(b<=e){
            int mid=(b+e)/2;
            if(nums[i][mid]==target){
                return true;
                break;
            }
            else if(nums[i][mid]<target){
                b=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    return false;
    }
};

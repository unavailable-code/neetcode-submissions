class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, index = -1;
    while (l <= r){
        int mid=(l+r)/2;
        if(nums[mid]==target){
            index=mid;
            return index;
        }
        if(nums[l]<=nums[mid]){
            if(target>=nums[l] && target<nums[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else{
            if(target>nums[mid] && target<=nums[r]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
    return index;
    }
};

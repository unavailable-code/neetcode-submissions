class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
    int ans=1001;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]<nums[r]){
            r=mid-1;
            ans=min(ans,nums[mid]);
        }
        else{
            l=mid+1;
            ans=min(ans,nums[mid]);
        }
    }
    return ans;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int loc=-1,b=0,e=nums.size()-1,mid=0;
    while(b<=e){
        mid=(b+e)/2;
        if(nums[mid]==target){
            loc=mid;
            break;
        }
        else if(nums[mid]<target){
            b=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return loc;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
    vector<int> ans(nums.size());
    int prev = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            ans[i] = prev;
            continue;
        }
        prev *= nums[i - 1];
        ans[i] = prev;
    }
    prev = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i == nums.size() - 1)
        {
            ans[i] *= prev;
            continue;
        }
        prev *= nums[i + 1];
        ans[i] *= prev;
    }
    
    return ans;
    }
};

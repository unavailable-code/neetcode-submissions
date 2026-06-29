class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
    vector<int> prefix(nums.size());
    vector<int> suffix(nums.size());
    vector<int> ans(nums.size());
    int prev = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0)
        {
            prefix[i] = prev;
            continue;
        }
        prev *= nums[i - 1];
        prefix[i] = prev;
    }
    prev = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i == nums.size() - 1)
        {
            suffix[i] = prev;
            continue;
        }
        prev *= nums[i + 1];
        suffix[i] = prev;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int answer = prefix[i] * suffix[i];
        ans[i] = answer;
    }

    return ans;
    }
};

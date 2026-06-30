class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {
            if (st.count(num - 1))
                continue;

            int length = 1;
            int current = num;

            while (st.count(current + 1)) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 1,ans=1;
    unordered_set<char> freq;
    if(s.empty()) return 0;
    freq.insert(s[l]);
    while (r < s.length())
    {
        if (freq.size() == 0)
        {
            freq.insert(s[l]);
            
        }
        if (freq.count(s[r]))
        {
            while(s[l]!=s[r] && l<=r){
                freq.erase(s[l]);
                l++;
            }
            freq.erase(s[l]);
            l++;
            freq.insert(s[r]);
            r++;
            ans= max(ans,(int)freq.size());
        }
        else
        {
            freq.insert(s[r]);
            r++;
            ans= max(ans,(int)freq.size());
        }
    }
    return ans;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map <int,int> count;
    for(int x : nums){
        count[x]++;
    }
    
    vector<pair<int,int>> freq(count.begin(),count.end());
    sort(freq.begin(),freq.end(),[](const auto &a, const auto &b){
        return a.second>b.second;
    });
    vector <int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(freq[i].first);
    }
return ans;
    }
};

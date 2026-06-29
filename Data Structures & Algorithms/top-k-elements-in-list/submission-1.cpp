class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> count;
    for(int x : nums){
        count[x]++;
    }
    
    vector<vector<int>> bucket(nums.size()+1);
    for(auto p : count){
        int num=p.first;
        int freq=p.second;

        bucket[freq].push_back(num);
    }

    vector <int> ans;
    for(int i= bucket.size()-1;i>=0;i--){
        for(int x: bucket[i]){
            ans.push_back(x);

            if(ans.size()==k){
                
                return ans;
            }
        }
    }
    return ans;
    }
};

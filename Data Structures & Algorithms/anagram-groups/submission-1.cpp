class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> groups;

    for(string x: strs){
        string key=x;
        sort(key.begin(),key.end());

        groups[key].push_back(x);
    }
    vector<vector<string>> ans;
    for(auto p: groups){
        ans.push_back(p.second);
    }
    return ans;
    }
};

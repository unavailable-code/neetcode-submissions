class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          vector<vector<string>> groupAnagrams1;
    vector<string> group;
    bool flag=true;
    unordered_map<char, int> map;
    unordered_map<char, int> temp;
    for (int i = 0; i < strs.size(); i++)
    {
        group.clear();
        map.clear();
        temp.clear();
        group.push_back(strs[i]);
        for (char x : strs[i])
        {
            map[x]++;
            temp[x]++;
        }
        for (int j = i + 1; j < strs.size(); j++)
        {
            if (strs[i].length() != strs[j].length())
            {
                continue;
            }
            for (char x : strs[j])
            {
                temp[x]--;
            }
            for (auto p : temp)
            {
                if (p.second != 0)
                {
                    flag=false;
                    
                }
            }
            if(flag==true){
                group.push_back(strs[j]);
                    strs.erase(strs.begin() + j);
                    j--;
            }
            flag=true;
            temp.clear();
            temp=map;
            
        }
        groupAnagrams1.push_back(group);
    }
    return groupAnagrams1;
    }
};

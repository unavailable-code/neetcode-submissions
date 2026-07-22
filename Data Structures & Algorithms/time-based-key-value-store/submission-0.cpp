class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &v= mp[key];
        string ans="";
        int time=0;
       if(!mp.count(key)){
            return "";
       }
        int l=0,r=mp[key].size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid].first<=timestamp){
                ans=v[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
       } 
    
};

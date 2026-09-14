class Solution {
public:
bool dfs(int src,vector<bool> &vis, vector<bool> &recPath,vector<vector<int>>& adj,stack<int> &s){
        vis[src]=true;
        recPath[src]=true;
        for(int v:adj[src]){
            if(!vis[v]){
                if(dfs(v,vis,recPath,adj,s)){
                    return true;
                }
            }
            else if(recPath[v]){
                return true;
            }
        }
            s.push(src);
            
        recPath[src]=false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        stack<int> s;
        vector<vector<int>> adj(n);
        vector<int> ans;
        for(auto edge: edges){
            int v=edge[0];
            int u=edge[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,recPath,adj,s)){
                    return {};
                }
            }   
        }
        
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

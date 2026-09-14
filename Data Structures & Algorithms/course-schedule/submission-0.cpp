class Solution {
public:
    bool dfs(int src,vector<bool> &vis, vector<bool> &recPath,vector<vector<int>>& adj){
        vis[src]=true;
        recPath[src]=true;
        for(int v:adj[src]){
            if(!vis[v]){
                if(dfs(v,vis,recPath,adj)){
                    return true;
                }
            }
            else if(recPath[v]){
                return true;
            }
        }
            
        recPath[src]=false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        vector<vector<int>> adj(n);
        for (auto edge: edges){
            int v=edge[0];
            int u=edge[1];
            adj[u].push_back(v);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,recPath,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};
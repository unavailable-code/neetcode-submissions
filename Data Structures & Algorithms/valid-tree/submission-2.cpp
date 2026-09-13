class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis,int &count) {
        vis[node] = true;
        count++;
        for(int neighbor : adj[node]) {

            if(!vis[neighbor]) {
                if(!dfs(neighbor, node, adj, vis,count))
                    return false;
            }
            else if(neighbor != parent) {
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1)
            return false;
        int count=0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool flag= dfs(0, -1, adj, vis,count);
        if(count!=n){
            flag=false;
        }
        return flag;
    }
};
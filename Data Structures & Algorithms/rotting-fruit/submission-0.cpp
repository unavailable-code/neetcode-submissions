class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        while(q.size()>0){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();

            ans=max(ans,time);
            vector<int> dx={-1,1,0,0};
            vector<int> dy={0,0,1,-1};
            for(int k=0;k<4;k++){
                int newI=i+dx[k];
                int newJ=j+dy[k];
                if(newI >= 0 && newI < n &&
                   newJ >= 0 && newJ < m &&
                   !vis[newI][newJ] &&
                   grid[newI][newJ] == 1){
                    q.push({{newI,newJ}, time+1});
                    vis[newI][newJ]=true;
                }
            }
        }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1 && !vis[i][j]){
                        return -1;
                    }
                }
            }
            return ans;
    }
};

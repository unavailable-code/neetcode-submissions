class Solution {
public:

    void numIslandsHelper(vector<vector<char>>& grid,int row, int col, int &count){
        vector<int> dx= {-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        grid[row][col]='0';
        for(int i=0;i<4;i++){
            if(row+dx[i]<0 || col+dy[i]<0 || row+dx[i]>grid.size()-1 || col+dy[i]>grid[0].size()-1){
                continue;
            }
            if(grid[row+dx[i]][col+dy[i]]=='1'){
                numIslandsHelper(grid,row+dx[i],col+dy[i],count);
            }
        }
        }
    
    int numIslands(vector<vector<char>>& grid) {
        int i=grid.size();
        int j=grid[0].size();
        int count=0;
        for(int row=0;row<i;row++){
            for(int col=0;col<j;col++){
                if(grid[row][col]=='1'){
                count++;
                numIslandsHelper(grid,row,col,count);
                } 
            }
        }
        return count;
    }
};
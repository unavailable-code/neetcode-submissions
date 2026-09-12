class Solution {
public:
    void change(vector<vector<char>> &board, int i,int j){
        board[i][j]='*';
        vector<int> dx={0,0,-1,1};
        vector<int> dy={1,-1,0,0};
        for(int a=0;a<4;a++){
            int cx=dx[a]+i;
            int cy=dy[a]+j;
            if(cx>=0 && cx<board.size() && cy>=0 && cy<board[0].size() && board[cx][cy]=='O'){
                change(board,cx,cy);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1){
                    if(board[i][j]=='O'){
                        change(board,i,j);
                    }
                }
            }
        }
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]=='O'){
                        board[i][j]='X';
                    }
                }
            }
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]=='*'){
                        board[i][j]='O';
                    }
                }
            }
        
    }
};

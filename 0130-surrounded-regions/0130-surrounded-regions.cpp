class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
        if(board[i][j]=='X')
            return;
        board[i][j]='1';
        if(i>0 && board[i-1][j]=='O')
            dfs(i-1,j,board);
        if(j>0 && board[i][j-1]=='O')
            dfs(i,j-1,board);
        if(i<board.size()-1 && board[i+1][j]=='O')
            dfs(i+1,j,board);
        if(j<board[0].size()-1 && board[i][j+1]=='O')
            dfs(i,j+1,board);
        
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            dfs(i,0,board);
            dfs(i,n-1,board);
        }
        for(int j=0;j<n;j++){
            dfs(0,j,board);
            dfs(m-1,j,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='1')
                    board[i][j]='O';
            }
        }
        
        
    }
};
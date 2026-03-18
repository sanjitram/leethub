class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,int k,int i,int j){
        if(k==word.size())  return true;
        bool a=false,b=false,c=false,d=false;
        char t=board[i][j];
        board[i][j]='*';
        if(j+1<board[0].size() && board[i][j+1]==word[k])
            a=dfs(board,word,k+1,i,j+1);
        if(j-1>=0 && board[i][j-1]==word[k])
            b=dfs(board,word,k+1,i,j-1);
        if(i+1<board.size() && board[i+1][j]==word[k])
            c=dfs(board,word,k+1,i+1,j);
        if(i-1>=0 && board[i-1][j]==word[k])
            d=dfs(board,word,k+1,i-1,j);
        board[i][j]=t;
        return (a||b||c||d);

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    vector<vector<char>> b=board;
                    bool ans=dfs(b,word,1,i,j);
                    if(ans) return true;
                }

            }
        }
        return false;
    }
};
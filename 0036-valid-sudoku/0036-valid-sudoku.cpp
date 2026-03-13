class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<set<int>>> v(3,vector<set<int>> (3));

        for(int i=0;i<9;i++){
            map<char,int> m;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')    continue;
                m[board[i][j]]++;
                if(m[board[i][j]]>1)
                    return false;
                int d=board[i][j]-'0';
                if(v[i/3][j/3].find(d)==v[i/3][j/3].end())  v[i/3][j/3].insert(d);
                else
                    return false;

            }
        }
        for(int j=0;j<9;j++){
            map<char,int> m;
            for(int i=0;i<9;i++){
                if(board[i][j]=='.')    continue;
                m[board[i][j]]++;
                if(m[board[i][j]]>1)
                    return false;
            }
        }
        return true;


    }
};
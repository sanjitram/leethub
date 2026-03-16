class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> si,sj;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    si.insert(i);
                    sj.insert(j);
                }
            }
        }
        for(int i:si){
            for(int j=0;j<m;j++){
                matrix[i][j]=0;
            }
        }
        for(int j:sj){
            for(int i=0;i<n;i++){
                matrix[i][j]=0;
            }
        }
    }
};
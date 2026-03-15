class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> m=matrix;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=m[n-1-j][i];
            }
        }
    }
};

// x,y
// y,n-1-x

// n-1-y,x
// x,y

